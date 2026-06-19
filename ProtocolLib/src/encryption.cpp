#include "encryption/encryption.hpp"

using namespace protocol;

EncryptData Encryption::encrypt(const encypt_data_t& data, const encypt_data_t& key) {
    encypt_data_t iv(12);
    RAND_bytes(iv.data(), iv.size());

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();

    EVP_EncryptInit(ctx, EVP_aes_128_gcm(), key.data(), iv.data());

    encypt_data_t ciphertext(data.size());

    int actual_size = 0, final_size = 0;

    EVP_EncryptUpdate(ctx, ciphertext.data(), &actual_size, data.data(), data.size());
    EVP_EncryptFinal(ctx, ciphertext.data() + actual_size, &final_size);

    encypt_data_t tag(AES_BLOCK_SIZE);
    EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, AES_BLOCK_SIZE, tag.data());

    EVP_CIPHER_CTX_free(ctx);

    return { ciphertext, iv, tag };
}

encypt_data_t Encryption::decrypt(const EncryptData& ciphertext,
                                  const encypt_data_t& key) {
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit(ctx, EVP_aes_128_gcm(), key.data(), ciphertext.iv.data());

    int actual_size = 0, final_size = 0;

    encypt_data_t data(ciphertext.data.size());
    EVP_DecryptUpdate(ctx, data.data(), &actual_size, ciphertext.data.data(),
                      ciphertext.data.size());

    auto tag = ciphertext.tag;
    EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, AES_BLOCK_SIZE, tag.data());

    int ret = EVP_DecryptFinal(ctx, data.data(), &final_size);
    EVP_CIPHER_CTX_free(ctx);

    if (ret != 1) {
        throw std::runtime_error("decrypt failure");
    }

    return data;
}
