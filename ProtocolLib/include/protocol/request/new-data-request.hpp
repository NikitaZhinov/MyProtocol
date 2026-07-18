#pragma once

#include "request.hpp"

#include <string>
#include <string_view>

namespace protocol::request {
    /**
     * @brief A request used to create new data on the server. It stores the user's ID and
     * message data.
     */
    class NewDataRequest final : public Request {
        std::uint64_t user_id_ = 0;
        std::string data_;

    public:
        /**
         * @brief Creates an object of the class with default parameters.
         */
        NewDataRequest();

        /**
         * @brief Creates an object of the class with the specified parameters.
         * @param user_id A user ID.
         * @param data A message data.
         */
        NewDataRequest(std::uint64_t user_id, const std::string_view& data);

        /**
         * @brief Sets a user ID.
         * @param user_id A new user ID.
         */
        void setUserId(std::size_t user_id);

        /**
         * @brief Sets a message data.
         * @param user_id A new message data.
         */
        void setData(const std::string_view& data);

        /**
         * @brief Returns a user id.
         * @return std::uint64_t
         */
        std::uint64_t getUserId() const;

        /**
         * @brief Returns a message data.
         * @return std::string
         */
        std::string getData() const;
    };
}  // namespace protocol::request
