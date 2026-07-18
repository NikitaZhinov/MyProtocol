#pragma once

#include "protocol/serialization/utils.hpp"

namespace protocol::deserialization::utils {
    /**
     * @brief Auxiliary function for deserializing RequestType.
     * @param data A serialized RequestType
     * @return request::RequestType
     */
    request::RequestType
    deserializeRequestType(const serialization::utils::serialize_data_t& data);

    /**
     * @brief Auxiliary function for deserializing ResponseType.
     * @param data A serialized ResponseType
     * @return response::ResponseType
     */
    response::ResponseType
    deserializeResponseType(const serialization::utils::serialize_data_t& data);

    /**
     * @brief An auxiliary function for deserializing numbers.
     * @param data A serialized 64 bit number
     * @return std::uint64_t
     */
    std::uint64_t deserializateNumber(const serialization::utils::serialize_data_t& data);

    /**
     * Auxiliary function for strings.
     * @param data A serialized string
     * @return std::string
     */
    std::string deserializateStr(const serialization::utils::serialize_data_t& data);
}  // namespace protocol::deserialization::utils
