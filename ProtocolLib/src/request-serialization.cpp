#include "serialization/request-serialization.hpp"

using namespace protocol;

RequestSerialization::RequestSerialization(request::RequestType serialization_type) :
    serialization_type_(serialization_type) {}

request::RequestType RequestSerialization::getSerializationType() const {
    return serialization_type_;
}
