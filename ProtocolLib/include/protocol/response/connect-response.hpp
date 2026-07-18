#pragma once

#include "response.hpp"

#include <vector>

namespace protocol::response {
    /**
     * @brief A response sending the servers's public key to the client. ATTENTION: IT IS
     * NOT SUBJECT TO ENCRYPTION!
     */
    class ConnectResponse final : public Response {
        std::vector<std::uint8_t> public_key_;

    public:
        /**
         * @brief Creates an object of the class with default parameters.
         */
        ConnectResponse();

        /**
         * @brief Creates an object of the class with the specified parameters.
         * @param public_key A public key.
         */
        ConnectResponse(const std::vector<std::uint8_t>& public_key);

        /**
         * @brief Creates an object of the class with the specified parameters.
         * @param public_key A public key.
         */
        ConnectResponse(std::vector<std::uint8_t>&& public_key);

        /**
         * @brief Sets public key.
         * @param public_key A public key.
         */
        void setPublicKey(const std::vector<std::uint8_t>& public_key);

        /**
         * @brief Sets public key.
         * @param public_key A public key.
         */
        void setPublicKey(std::vector<std::uint8_t>&& public_key);

        /**
         * @brief Returns public key.
         * @return std::vector<std::uint8_t>
         */
        std::vector<std::uint8_t> getPublicKey() const;
    };
}  // namespace protocol::response
