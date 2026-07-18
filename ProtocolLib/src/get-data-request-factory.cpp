#include "protocol/protocol.hpp"

protocol::request::GetDataRequestFactory::GetDataRequestFactory() :
    RequestFactory(RequestType::GetData) {}

protocol::request::GetDataRequestFactory::request_ptr
protocol::request::GetDataRequestFactory::create() const {
    return std::make_shared<GetDataRequest>();
}
