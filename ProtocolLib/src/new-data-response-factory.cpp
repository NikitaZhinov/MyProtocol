#include "protocol/protocol.hpp"

protocol::response::NewDataResponseFactory::NewDataResponseFactory() :
    ResponseFactory(ResponseType::NewData) {}

protocol::response::ResponseFactory::response_ptr
protocol::response::NewDataResponseFactory::create() const {
    return std::make_shared<NewDataResponse>();
}
