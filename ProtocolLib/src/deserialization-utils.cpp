#include "protocol/protocol.hpp"

using protocol::request::RequestType;
using protocol::response::ResponseType;
using protocol::serialization::utils::serialize_data_t;

RequestType
protocol::deserialization::utils::deserializeRequestType(const serialize_data_t& data) {
    return RequestType(data.front());
}

ResponseType
protocol::deserialization::utils::deserializeResponseType(const serialize_data_t& data) {
    return ResponseType(data.front());
}

std::uint64_t
protocol::deserialization::utils::deserializateNumber(const serialize_data_t& data) {
    std::uint64_t number = 0;

    for (int i = 0; i < 8; ++i) {
        number |= static_cast<std::uint64_t>(data[i]) << ((7 - i) * 8);
    }

    return number;
}

std::string
protocol::deserialization::utils::deserializateStr(const serialize_data_t& data) {
    return std::string(data.begin(), data.end());
}
