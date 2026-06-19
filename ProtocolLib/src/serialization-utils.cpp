#include "serialization/utils.hpp"

using namespace protocol::utils;

serialize_data_t protocol::utils::serialize(request::RequestType type) {
    return serialize_data_t { static_cast<std::uint8_t>(type) };
}

serialize_data_t protocol::utils::serialize(response::ResponseType type) {
    return serialize_data_t { static_cast<std::uint8_t>(type) };
}

serialize_data_t protocol::utils::serialize(std::uint64_t number) {
    serialize_data_t s_number;

    for (int i = 7; i >= 0; --i) {
        int j = 7 - i;
        s_number.push_back((number << (j * 8)) >> ((i + j) * 8));
    }

    return s_number;
}

serialize_data_t protocol::utils::serialize(const std::string& str) {
    return serialize_data_t(str.begin(), str.end());
}
