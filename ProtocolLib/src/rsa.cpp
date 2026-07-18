#include "protocol/encryption/rsa.hpp"

#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <print>

using protocol::encryption::rsa::KeyPair;

static std::string opensslLastError() {
    unsigned long err = ERR_get_error();
    if (err == 0) {
        return "unknown OpenSSL error";
    }
    char buf[256];
    ERR_error_string_n(err, buf, sizeof(buf));
    return std::string(buf);
}

KeyPair protocol::encryption::rsa::generatePairKey() {
    constexpr int bits = 2048;

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, nullptr);

    EVP_PKEY_keygen_init(ctx);

    EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, bits);

    EVP_PKEY* pkey = nullptr;
    EVP_PKEY_keygen(ctx, &pkey);

    EVP_PKEY_CTX_free(ctx);

    BIO* bio = BIO_new(BIO_s_mem());
    PEM_write_bio_PrivateKey(bio, pkey, nullptr, nullptr, 0, nullptr, nullptr);
    BUF_MEM* bptr = nullptr;
    BIO_get_mem_ptr(bio, &bptr);

    std::vector<std::uint8_t> private_key(bptr->data, bptr->data + bptr->length);

    PEM_write_bio_PUBKEY(bio, pkey);
    BIO_get_mem_ptr(bio, &bptr);

    std::vector<std::uint8_t> public_key(bptr->data, bptr->data + bptr->length);
    BIO_free(bio);

    EVP_PKEY_free(pkey);

    return { private_key, public_key };
}

std::vector<std::uint8_t>
protocol::encryption::rsa::encrypt(const std::vector<std::uint8_t>& data,
                                   const std::vector<std::uint8_t>& public_key) {
    BIO* bio = BIO_new_mem_buf(public_key.data(), static_cast<int>(public_key.size()));

    EVP_PKEY* pkey = PEM_read_bio_PUBKEY(bio, nullptr, nullptr, nullptr);
    BIO_free(bio);

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);

    EVP_PKEY_encrypt_init(ctx);

    EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING);

    std::size_t outLen = 0;
    if (EVP_PKEY_encrypt(ctx, nullptr, &outLen, data.data(), data.size()) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        throw std::runtime_error("EVP_PKEY_encrypt (size): " + opensslLastError());
    }

    std::vector<std::uint8_t> ciphertext(outLen);
    if (EVP_PKEY_encrypt(ctx, ciphertext.data(), &outLen, data.data(), data.size()) <=
        0) {
        EVP_PKEY_CTX_free(ctx);
        throw std::runtime_error("EVP_PKEY_encrypt (data): " + opensslLastError());
    }

    ciphertext.resize(outLen);

    EVP_PKEY_CTX_free(ctx);
    EVP_PKEY_free(pkey);

    return ciphertext;
}

std::vector<std::uint8_t>
protocol::encryption::rsa::decrypt(const std::vector<std::uint8_t>& ciphertext,
                                   const std::vector<std::uint8_t>& private_key) {
    BIO* bio = BIO_new_mem_buf(private_key.data(), static_cast<int>(private_key.size()));

    EVP_PKEY* pkey = PEM_read_bio_PrivateKey(bio, nullptr, nullptr, nullptr);
    BIO_free(bio);

    EVP_PKEY_CTX* ctx = EVP_PKEY_CTX_new(pkey, nullptr);

    EVP_PKEY_decrypt_init(ctx);

    EVP_PKEY_CTX_set_rsa_padding(ctx, RSA_PKCS1_OAEP_PADDING);

    std::size_t outLen = 0;
    if (EVP_PKEY_decrypt(ctx, nullptr, &outLen, ciphertext.data(), ciphertext.size()) <=
        0) {
        EVP_PKEY_CTX_free(ctx);
        throw std::runtime_error("EVP_PKEY_decrypt (size): " + opensslLastError());
    }

    std::vector<std::uint8_t> plaintext(outLen);
    if (EVP_PKEY_decrypt(ctx, plaintext.data(), &outLen, ciphertext.data(),
                         ciphertext.size()) <= 0) {
        EVP_PKEY_CTX_free(ctx);
        throw std::runtime_error("EVP_PKEY_decrypt (data): " + opensslLastError());
    }

    EVP_PKEY_CTX_free(ctx);
    EVP_PKEY_free(pkey);

    return plaintext;
}
