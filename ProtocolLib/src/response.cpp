#include "protocol/protocol.hpp"

protocol::response::Response::Response(ResponseType type) : type_(type) {}

protocol::response::ResponseType protocol::response::Response::getType() const {
    return type_;
}
