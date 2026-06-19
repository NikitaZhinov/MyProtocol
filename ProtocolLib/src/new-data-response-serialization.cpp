#include "serialization/new-data-response-serialization.hpp"

#include "response/new-data-response.hpp"
#include "serialization/utils.hpp"

#include <stdexcept>

using namespace protocol;

NewDataResponseSerialization::NewDataResponseSerialization() :
    ResponseSerialization(response::ResponseType::NewData) {}

utils::serialize_data_t
NewDataResponseSerialization::serialize(ResponseFactory::response_ptr msg) {
    if (msg->getType() != getSerializationType()) {
        throw std::logic_error("cannot serialize");
    }

    auto message_ptr = std::static_pointer_cast<NewDataResponse>(msg);

    auto& message = *message_ptr;

    utils::serialize_data_t serialize_message;

    serialize_message.append_range(utils::serialize(message.getType()));
    serialize_message.append_range(utils::serialize(message.getDataId()));

    return serialize_message;
}
