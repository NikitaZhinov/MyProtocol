#include "protocol/protocol.hpp"

protocol::response::ResponseFactory::ResponseFactory(ResponseType creation_type) :
    creation_type_(creation_type) {}

protocol::response::ResponseType
protocol::response::ResponseFactory::getCreationType() const {
    return creation_type_;
}
