#include "protocol/protocol.hpp"

#include <stdexcept>

using protocol::serialization::utils::serialize_data_t;

protocol::serialization::NewDataResponseSerialization::NewDataResponseSerialization() :
    ResponseSerialization(response::ResponseType::NewData) {}

serialize_data_t protocol::serialization::NewDataResponseSerialization::serialize_(
    response::ResponseFactory::response_ptr response) const {
    auto message_ptr = std::static_pointer_cast<response::NewDataResponse>(response);

    auto& message = *message_ptr;

    serialize_data_t serialize_message;

    serialize_message.append_range(utils::serialize(message.getType()));
    serialize_message.append_range(utils::serialize(message.getDataId()));

    return serialize_message;
}
