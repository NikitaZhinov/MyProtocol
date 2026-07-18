#include "protocol/protocol.hpp"

using protocol::request::RequestType;

protocol::deserialization::RequestDeserialization::RequestDeserialization(
    RequestType deserialization_type) :
    deserialization_type_(deserialization_type) {}

protocol::request::RequestFactory::request_ptr
protocol::deserialization::RequestDeserialization::deserialize(
    const serialization::utils::serialize_data_t& data) const {
    if (utils::deserializeRequestType(data) != getDeserializationType()) {
        throw std::logic_error("cannot deserializate");
    }

    return deserialize_(
        serialization::utils::serialize_data_t(data.begin() + 1, data.end()));
}

RequestType
protocol::deserialization::RequestDeserialization::getDeserializationType() const {
    return deserialization_type_;
}
