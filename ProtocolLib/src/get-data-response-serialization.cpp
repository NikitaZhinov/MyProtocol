#include "serialization/get-data-response-serialization.hpp"

#include "response/get-data-response.hpp"
#include "serialization/utils.hpp"

#include <stdexcept>

using namespace protocol;

GetDataResponseSerialization::GetDataResponseSerialization() :
    ResponseSerialization(response::ResponseType::GetData) {}

utils::serialize_data_t
GetDataResponseSerialization::serialize(ResponseFactory::response_ptr msg) {
    if (msg->getType() != getSerializationType()) {
        throw std::logic_error("cannot serialize");
    }

    auto message_ptr = std::static_pointer_cast<GetDataResponse>(msg);

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
