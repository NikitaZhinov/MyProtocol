#include "protocol/protocol.hpp"

using protocol::response::ResponseType;

protocol::deserialization::ResponseDeserialization::ResponseDeserialization(
    ResponseType deserialization_type) :
    deserialization_type_(deserialization_type) {}

protocol::response::ResponseFactory::response_ptr
protocol::deserialization::ResponseDeserialization::deserialize(
    const serialization::utils::serialize_data_t& data) const {
    if (utils::deserializeResponseType(data) != getDeserializationType()) {
        throw std::logic_error("cannot deserializate");
    }

    return deserialize_(
        serialization::utils::serialize_data_t(data.begin() + 1, data.end()));
}

ResponseType
protocol::deserialization::ResponseDeserialization::getDeserializationType() const {
    return deserialization_type_;
}
