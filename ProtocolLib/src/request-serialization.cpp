#include "protocol/protocol.hpp"

using protocol::request::RequestType;

protocol::serialization::RequestSerialization::RequestSerialization(
    RequestType serialization_type) :
    serialization_type_(serialization_type) {}

protocol::serialization::utils::serialize_data_t
protocol::serialization::RequestSerialization::serialize(
    request::RequestFactory::request_ptr request) const {
    if (request->getType() != getSerializationType()) {
        throw std::logic_error("cannot serialize");
    }

    return serialize_(request);
}

RequestType protocol::serialization::RequestSerialization::getSerializationType() const {
    return serialization_type_;
}
