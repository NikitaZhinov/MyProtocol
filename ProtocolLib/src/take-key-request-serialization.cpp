#include "protocol/protocol.hpp"

#include <stdexcept>

protocol::serialization::TakeKeyRequestSerialization::TakeKeyRequestSerialization() :
    RequestSerialization(protocol::request::RequestType::TakeKey) {}

protocol::serialization::utils::serialize_data_t
protocol::serialization::TakeKeyRequestSerialization::serialize_(
    request::RequestFactory::request_ptr request) const {
    auto message_ptr = std::static_pointer_cast<request::TakeKeyRequest>(request);

    auto& message = *message_ptr;

    utils::serialize_data_t serialize_message;

    serialize_message.append_range(utils::serialize(message.getType()));
    serialize_message.append_range(message.getSecretKey());

    return serialize_message;
}
