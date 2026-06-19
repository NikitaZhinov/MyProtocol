#include "deserialization/utils.hpp"

using namespace protocol;
using namespace protocol::utils;

request::RequestType
protocol::utils::deserializeRequestType(const serialize_data_t& data) {
    return request::RequestType(data.front());
}

response::ResponseType
protocol::utils::deserializeResponseType(const serialize_data_t& data) {
    return response::ResponseType(data.front());
}

std::uint64_t protocol::utils::deserializateNumber(const serialize_data_t& data) {
    std::uint64_t number = 0;

    for (int i = 0; i < 8; ++i) {
        number |= static_cast<std::uint64_t>(data[i]) << ((7 - i) * 8);
    }

    return number;
}

std::string protocol::utils::deserializateStr(const serialize_data_t& data) {
    return std::string(data.begin(), data.end());
}
