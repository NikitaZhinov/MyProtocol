#include "protocol/protocol.hpp"

protocol::response::GetDataResponseFactory::GetDataResponseFactory() :
    ResponseFactory(ResponseType::GetData) {}

protocol::response::ResponseFactory::response_ptr
protocol::response::GetDataResponseFactory::create() const {
    return std::make_shared<GetDataResponse>();
}
