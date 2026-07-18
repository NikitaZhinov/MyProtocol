#include "protocol/protocol.hpp"

using protocol::response::ResponseType;

protocol::serialization::ResponseSerialization::ResponseSerialization(
    ResponseType serialization_type) :
    serialization_type_(serialization_type) {}

protocol::serialization::utils::serialize_data_t
protocol::serialization::ResponseSerialization::serialize(
    response::ResponseFactory::response_ptr response) const {
    if (response->getType() != getSerializationType()) {
        throw std::logic_error("cannot serialize");
    }

    return serialize_(response);
}

ResponseType
protocol::serialization::ResponseSerialization::getSerializationType() const {
    return serialization_type_;
}
