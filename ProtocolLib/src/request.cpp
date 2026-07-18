#include "protocol/protocol.hpp"

protocol::request::Request::Request(RequestType type) : type_(type) {}

protocol::request::RequestType protocol::request::Request::getType() const {
    return type_;
}
