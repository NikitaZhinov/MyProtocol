#pragma once

#include "response.hpp"

#include <string>
#include <vector>

namespace protocol {
    /**
     * @brief It is used for the server's response to a request to receive the created
     * data. Stores the amount of data, data ids and data.
     */
    class GetDataResponse final : public Response {
        std::size_t amount_data_ = 0;
        std::vector<std::uint64_t> ids_;
        std::vector<std::string> data_;

    public:
        /**
         * @brief Creates an object of the class with default parameters.
         */
        GetDataResponse();

        /**
         * @brief Creates an object of the class with the specified parameters.
         * @param amount_data Amount of data
         * @param data A data
         */
        GetDataResponse(const std::vector<std::pair<std::uint64_t, std::string>>& data);

        /**
         * @brief Sets a data.
         * @param user_id A new data
         */
        void setData(const std::vector<std::pair<std::uint64_t, std::string>>& data);

        /**
         * @brief Returns a amount of data.
         * @return std::size_t
         */
        std::size_t getAmountData() const;

        /**
         * @brief Returns a data ids.
         * @return std::vector<std::uint64_t>
         */
        std::vector<std::uint64_t> getDataIds() const;

        /**
         * @brief Returns a data.
         * @return std::vector<std::string>
         */
        std::vector<std::string> getData() const;
    };
}  // namespace protocol
