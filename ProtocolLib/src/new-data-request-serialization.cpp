#include "protocol/protocol.hpp"

#include <stdexcept>

using protocol::serialization::utils::serialize_data_t;

protocol::serialization::NewDataRequestSerialization::NewDataRequestSerialization() :
    RequestSerialization(request::RequestType::NewData) {}

serialize_data_t protocol::serialization::NewDataRequestSerialization::serialize_(
    request::RequestFactory::request_ptr request) const {
    auto message_ptr = std::static_pointer_cast<request::NewDataRequest>(request);

    auto& message = *message_ptr;

    utils::serialize_data_t serialize_message;

    serialize_message.append_range(utils::serialize(message.getType()));
    serialize_message.append_range(utils::serialize(message.getUserId()));
    serialize_message.append_range(utils::serialize(message.getData()));

    return serialize_message;
}
