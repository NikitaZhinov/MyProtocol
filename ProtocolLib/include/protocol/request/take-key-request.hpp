#pragma once

#include "request.hpp"

#include <vector>

namespace protocol::request {
    /**
     * @brief A request that sends a secret key to the server, which then encrypts the
     * rest of the messages.
     */
    class TakeKeyRequest final : public Request {
        std::vector<std::uint8_t> secret_key_;

    public:
        /**
         * @brief Creates an object of the class with default parameters.
         */
        TakeKeyRequest();

        /**
         * @brief Creates an object of the class with the specified parameters.
         * @param secret_key A secret key.
         */
        TakeKeyRequest(const std::vector<std::uint8_t>& secret_key);

        /**
         * @brief Creates an object of the class with the specified parameters.
         * @param secret_key A secret key.
         */
        TakeKeyRequest(std::vector<std::uint8_t>&& secret_key);

        /**
         * @brief Sets secret key.
         * @param secret_key A secret key.
         */
        void setSecretKey(const std::vector<std::uint8_t>& secret_key);

        /**
         * @brief Sets secret key.
         * @param secret_key A secret key.
         */
        void setSecretKey(std::vector<std::uint8_t>&& secret_key);

        /**
         * @brief Returns secret key.
         * @return std::vector<std::uint8_t>
         */
        std::vector<std::uint8_t> getSecretKey() const;
    };
}  // namespace protocol::request
