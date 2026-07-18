#include "protocol/protocol.hpp"

protocol::request::RequestFactory::RequestFactory(RequestType creation_type) :
    creation_type_(creation_type) {}

protocol::request::RequestType
protocol::request::RequestFactory::getCreationType() const {
    return creation_type_;
}
