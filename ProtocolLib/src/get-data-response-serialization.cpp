#include "protocol/protocol.hpp"

#include <stdexcept>

using protocol::serialization::utils::serialize_data_t;

protocol::serialization::GetDataResponseSerialization::GetDataResponseSerialization() :
    ResponseSerialization(response::ResponseType::GetData) {}

serialize_data_t protocol::serialization::GetDataResponseSerialization::serialize_(
    response::ResponseFactory::response_ptr response) const {
    auto message_ptr = std::static_pointer_cast<response::GetDataResponse>(response);

    auto& message = *message_ptr;

    utils::serialize_data_t serialize_message;

    serialize_message.append_range(utils::serialize(message.getType()));
    serialize_message.append_range(utils::serialize(message.getAmountData()));

    for (auto& id : message.getDataIds()) {
        serialize_message.append_range(utils::serialize(id));
    }

    for (auto& data : message.getData()) {
        serialize_message.append_range(utils::serialize(data));
        serialize_message.push_back('\0');
    }

    return serialize_message;
}
