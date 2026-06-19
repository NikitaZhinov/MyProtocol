#include "serialization/response-serialization.hpp"

using namespace protocol;

ResponseSerialization::ResponseSerialization(response::ResponseType serialization_type) :
    serialization_type_(serialization_type) {}

response::ResponseType ResponseSerialization::getSerializationType() const {
    return serialization_type_;
}
