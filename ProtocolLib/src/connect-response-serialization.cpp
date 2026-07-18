#include "protocol/protocol.hpp"

protocol::serialization::utils::serialize_data_t
protocol::serialization::ConnectResponseSerialization::serialize_(
    response::ResponseFactory::response_ptr response) const {
    auto message_ptr = std::static_pointer_cast<response::ConnectResponse>(response);

    auto& message = *message_ptr;

    utils::serialize_data_t serialize_message;

    serialize_message.append_range(utils::serialize(message.getType()));
    serialize_message.append_range(message.getPublicKey());

    return serialize_message;
}

protocol::serialization::ConnectResponseSerialization::ConnectResponseSerialization() :
    ResponseSerialization(protocol::response::ResponseType::Connect) {}
