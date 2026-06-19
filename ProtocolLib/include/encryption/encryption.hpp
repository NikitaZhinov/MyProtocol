#pragma once

#include <ranges>
#include <string>
#include <string_view>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <stdexcept>
#include <vector>

namespace protocol {
    /**
     * @brief Type for storing encrypted data.
     */
    using encypt_data_t = std::vector<std::uint8_t>;

    /**
     * @brief Stores encrypted data and encryption parameters.
     */
    struct EncryptData {
        /**
         * @brief An encrypted message.
         */
        encypt_data_t data;

        /**
         * @brief Initialization Vector. A random number that is added to the encryption.
         */
        std::vector<std::uint8_t> iv;

        /**
         * @brief Authentication Tag. Guarantees two properties: that the data was not
         * changed on the way, and that it was encrypted by the one who has the key.
         */
        std::vector<std::uint8_t> tag;
    };

    /**
     * @brief Responsible for encrypting and decrypting messages.
     */
    class Encryption final {
    public:
        /**
         * @brief Encrypts the message with the specified key.
         * @param data a message
         * @param key a key
         * @return EncryptData
         */
        static EncryptData encrypt(const encypt_data_t& data, const encypt_data_t& key);

        /**
         * @brief Decrypts the message with the specified key.
         * @param ciphertext an encrypted message
         * @param key a key
         * @return encypt_data_t
         */
        static encypt_data_t decrypt(const EncryptData& ciphertext,
                                     const encypt_data_t& key);
    };
}  // namespace protocol
