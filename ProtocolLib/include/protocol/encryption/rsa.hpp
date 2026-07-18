#pragma once

#include <ranges>
#include <string>
#include <string_view>
#include <stdexcept>
#include <vector>

namespace protocol::encryption::rsa {
    /**
     * @brief Stores a private + public key pair.
     */
    struct KeyPair {
        /**
         * @brief A private key.
         */
        std::vector<std::uint8_t> private_key;

        /**
         * @brief A public key.
         */
        std::vector<std::uint8_t> public_key;
    };

    /**
     * @brief Generates encryption keys.
     * @return KeyPair
     */
    KeyPair generatePairKey();

    /**
     * @brief Encrypts data using a public key using the RSA algorithm.
     * @param data A data
     * @param public_key A public key
     * @return std::vector<std::uint8_t>
     */
    std::vector<std::uint8_t> encrypt(const std::vector<std::uint8_t>& data,
                                      const std::vector<std::uint8_t>& public_key);

    /**
     * @brief Decrypts data using a private key using the RSA algorithm.
     * @param data A data
     * @param private_key A private key
     * @return std::vector<std::uint8_t>
     */
    std::vector<std::uint8_t> decrypt(const std::vector<std::uint8_t>& ciphertext,
                                      const std::vector<std::uint8_t>& private_key);
}  // namespace protocol::encryption::rsa
