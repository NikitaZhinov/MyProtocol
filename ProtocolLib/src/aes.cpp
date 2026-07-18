#include "protocol/encryption/aes.hpp"

#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

std::vector<std::uint8_t> protocol::encryption::aes::generateKey() {
    std::vector<std::uint8_t> key(32);
    RAND_bytes(key.data(), key.size());
    return key;
}

std::vector<std::uint8_t>
protocol::encryption::aes::encrypt(const std::vector<std::uint8_t>& data,
                                   const std::vector<std::uint8_t>& key) {
    std::vector<std::uint8_t> iv(12);
    RAND_bytes(iv.data(), iv.size());

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();

    EVP_EncryptInit(ctx, EVP_aes_256_gcm(), key.data(), iv.data());

    std::vector<std::uint8_t> ciphertext(data.size());

    int actual_size = 0, final_size = 0;

    EVP_EncryptUpdate(ctx, ciphertext.data(), &actual_size, data.data(), data.size());
    EVP_EncryptFinal(ctx, ciphertext.data() + actual_size, &final_size);

    std::vector<std::uint8_t> tag(AES_BLOCK_SIZE);
    EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, AES_BLOCK_SIZE, tag.data());

    EVP_CIPHER_CTX_free(ctx);

    std::vector<std::uint8_t> encypt_data;

    encypt_data.append_range(iv);
    encypt_data.append_range(ciphertext);
    encypt_data.append_range(tag);

    return encypt_data;
}

std::vector<std::uint8_t>
protocol::encryption::aes::decrypt(const std::vector<std::uint8_t>& ciphertext,
                                   const std::vector<std::uint8_t>& key) {

    std::vector<std::uint8_t> iv(ciphertext.begin(), ciphertext.begin() + 12);
    std::vector<std::uint8_t> encrypt_data(ciphertext.begin() + 12,
                                           ciphertext.end() - AES_BLOCK_SIZE);
    std::vector<std::uint8_t> tag(ciphertext.end() - AES_BLOCK_SIZE, ciphertext.end());

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit(ctx, EVP_aes_256_gcm(), key.data(), iv.data());

    int actual_size = 0, final_size = 0;

    std::vector<std::uint8_t> data(encrypt_data.size());
    EVP_DecryptUpdate(ctx, data.data(), &actual_size, encrypt_data.data(),
                      encrypt_data.size());

    EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, AES_BLOCK_SIZE, tag.data());

    int ret = EVP_DecryptFinal(ctx, data.data(), &final_size);
    EVP_CIPHER_CTX_free(ctx);

    if (ret != 1) {
        throw std::runtime_error("decrypt failure");
    }

    return data;
}
