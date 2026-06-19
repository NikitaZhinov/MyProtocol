#include "request/request-factory.hpp"

using namespace protocol;

RequestFactory::RequestFactory(request::RequestType creation_type) :
    creation_type_(creation_type) {}

request::RequestType RequestFactory::getCreationType() const {
    return creation_type_;
}
