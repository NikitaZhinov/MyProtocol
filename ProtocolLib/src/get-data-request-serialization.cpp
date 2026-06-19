#include "serialization/get-data-request-serialization.hpp"

#include "serialization/utils.hpp"
#include "request/get-data-request.hpp"

#include <stdexcept>

using namespace protocol;

GetDataRequestSerialization::GetDataRequestSerialization() :
    RequestSerialization(request::RequestType::GetData) {}

utils::serialize_data_t
GetDataRequestSerialization::serialize(RequestFactory::request_ptr msg) {
    if (msg->getType() != getSerializationType()) {
        throw std::logic_error("cannot serialize");
    }

    auto message_ptr = std::static_pointer_cast<GetDataRequest>(msg);

    auto& message = *message_ptr;

    utils::serialize_data_t serialize_message;

    serialize_message.append_range(utils::serialize(message.getType()));
    serialize_message.append_range(utils::serialize(message.getUserId()));

    return serialize_message;
}
