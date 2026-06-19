#include "response/response.hpp"

using namespace protocol;

Response::Response(response::ResponseType type) : type_(type) {}

response::ResponseType protocol::Response::getType() const {
    return type_;
}
