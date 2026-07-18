#pragma once

#include "response.hpp"

#include <string>
#include <string_view>

namespace protocol::response {
    /**
     * @brief It is used for the server's response to a request to create new data. It
     * stores the data ID.
     */
    class NewDataResponse final : public Response {
        std::uint64_t data_id_ = 0;

    public:
        /**
         * @brief Creates an object of the class with default parameters.
         */
        NewDataResponse();

        /**
         * @brief Creates an object of the class with the specified parameters.
         * @param data_id A data ID.
         */
        NewDataResponse(std::uint64_t data_id);

        /**
         * @brief Sets a data ID.
         * @param data_id A new data ID.
         */
        void setDataId(std::uint64_t data_id);

        /**
         * @brief Returns a data ID.
         * @return std::uint64_t
         */
        std::uint64_t getDataId() const;
    };
}  // namespace protocol::response
