#include "protocol/protocol.hpp"

protocol::response::ConnectResponseFactory::ConnectResponseFactory() :
    ResponseFactory(response::ResponseType::Connect) {}

protocol::response::ResponseFactory::response_ptr
protocol::response::ConnectResponseFactory::create() const {
    return std::make_shared<ConnectResponse>();
}
