#pragma once

#include "request.hpp"

#include <cstdint>

namespace protocol::request {
    /**
     * @brief A request that allows the client to receive all its requests stored on the
     * server. Stores the user's ID.
     */
    class GetDataRequest final : public Request {
        std::uint64_t user_id_ = 0;

    public:
        /**
         * @brief Creates an object of the class with default parameters.
         */
        GetDataRequest();

        /**
         * @brief Creates an object of the class with the specified parameters.
         * @param user_id A user ID.
         */
        GetDataRequest(std::uint64_t user_id);

        /**
         * @brief Sets a user ID.
         * @param user_id A new user ID.
         */
        void setUserId(std::uint64_t user_id);

        /**
         * @brief Returns a user id.
         * @return std::uint64_t
         */
        std::uint64_t getUserId() const;
    };
}  // namespace protocol::request
