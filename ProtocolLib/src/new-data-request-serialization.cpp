#include "serialization/new-data-request-serialization.hpp"

#include "request/new-data-request.hpp"
#include "serialization/utils.hpp"

#include <stdexcept>

using namespace protocol;

NewDataRequestSerialization::NewDataRequestSerialization() :
    RequestSerialization(request::RequestType::NewData) {}

utils::serialize_data_t
NewDataRequestSerialization::serialize(RequestFactory::request_ptr msg) {
    if (msg->getType() != getSerializationType()) {
        throw std::logic_error("cannot serialize");
    }

    auto message_ptr = std::static_pointer_cast<NewDataRequest>(msg);

    auto& message = *message_ptr;

    utils::serialize_data_t serialize_message;

    serialize_message.append_range(utils::serialize(message.getType()));
    serialize_message.append_range(utils::serialize(message.getUserId()));
    serialize_message.append_range(utils::serialize(message.getData()));

    return serialize_message;
}
