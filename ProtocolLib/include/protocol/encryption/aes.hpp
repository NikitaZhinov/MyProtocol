#pragma once

#include <ranges>
#include <string>
#include <string_view>
#include <stdexcept>
#include <vector>

namespace protocol::encryption::aes {
    /**
     * @brief Generates a random 256 bit encryption key.
     * @return std::vector<std::uint8_t>
     */
    std::vector<std::uint8_t> generateKey();

    /**
     * @brief Encrypts the message using the specified key using the AES algorithm.
     * @param data A message
     * @param key A key
     * @return std::vector<std::uint8_t>
     */
    std::vector<std::uint8_t> encrypt(const std::vector<std::uint8_t>& data,
                                      const std::vector<std::uint8_t>& key);

    /**
     * @brief Decrypts the message using the specified key using the AES algorithm.
     * @param ciphertext An encrypted message
     * @param key A key
     * @return std::vector<std::uint8_t>
     */
    std::vector<std::uint8_t> decrypt(const std::vector<std::uint8_t>& ciphertext,
                                      const std::vector<std::uint8_t>& key);
}  // namespace protocol::encryption::aes
