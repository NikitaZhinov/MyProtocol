#pragma once

#include "serialization/utils.hpp"

namespace protocol::utils {
    /**
     * @brief Auxiliary function for deserializing RequestType.
     * @param data a serialized RequestType
     * @return request::RequestType
     */
    request::RequestType deserializeRequestType(const serialize_data_t& data);

    /**
     * @brief Auxiliary function for deserializing ResponseType.
     * @param data a serialized ResponseType
     * @return response::ResponseType
     */
    response::ResponseType deserializeResponseType(const serialize_data_t& data);

    /**
     * @brief An auxiliary function for deserializing numbers.
     * @param data a serialized 64 bit number
     * @return std::uint64_t
     */
    std::uint64_t deserializateNumber(const serialize_data_t& data);

    /**
     * Auxiliary function for strings.
     * @param data a serialized string
     * @return std::string
     */
    std::string deserializateStr(const serialize_data_t& data);
}  // namespace protocol::utils
