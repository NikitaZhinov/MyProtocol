#include "deserialization/response-deserialization.hpp"

using namespace protocol;

ResponseDeserialization::ResponseDeserialization(
    response::ResponseType deserialization_type) :
    deserialization_type_(deserialization_type) {}

response::ResponseType ResponseDeserialization::getDeserializationType() const {
    return deserialization_type_;
}
