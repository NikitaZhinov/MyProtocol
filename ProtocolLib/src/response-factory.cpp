#include "response/response-factory.hpp"

using namespace protocol;

ResponseFactory::ResponseFactory(response::ResponseType creation_type) :
    creation_type_(creation_type) {}

response::ResponseType ResponseFactory::getCreationType() const {
    return creation_type_;
}
