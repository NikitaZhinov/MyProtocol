#include "request/request.hpp"

using namespace protocol;

Request::Request(request::RequestType type) : type_(type) {}

request::RequestType protocol::Request::getType() const {
    return type_;
}
