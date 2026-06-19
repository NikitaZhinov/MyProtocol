#include "deserialization/request-deserialization.hpp"

using namespace protocol;

RequestDeserialization::RequestDeserialization(
    request::RequestType deserialization_type) :
    deserialization_type_(deserialization_type) {}

request::RequestType RequestDeserialization::getDeserializationType() const {
    return deserialization_type_;
}
