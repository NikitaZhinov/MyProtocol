#include "protocol/protocol.hpp"

protocol::request::NewDataRequestFactory::NewDataRequestFactory() :
    RequestFactory(request::RequestType::NewData) {}

protocol::request::NewDataRequestFactory::request_ptr
protocol::request::NewDataRequestFactory::create() const {
    return std::make_shared<NewDataRequest>();
}
