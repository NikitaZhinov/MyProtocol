#include "protocol/protocol.hpp"

#include <stdexcept>

using protocol::serialization::utils::serialize_data_t;

protocol::serialization::GetDataRequestSerialization::GetDataRequestSerialization() :
    RequestSerialization(request::RequestType::GetData) {}

serialize_data_t protocol::serialization::GetDataRequestSerialization::serialize_(
    request::RequestFactory::request_ptr request) const {
    auto message_ptr = std::static_pointer_cast<request::GetDataRequest>(request);

    auto& message = *message_ptr;

    utils::serialize_data_t serialize_message;

    serialize_message.append_range(utils::serialize(message.getType()));
    serialize_message.append_range(utils::serialize(message.getUserId()));

    return serialize_message;
}
