#include "protocol/request/take-key-request-factory.hpp"

protocol::request::TakeKeyRequestFactory::TakeKeyRequestFactory() :
    RequestFactory(request::RequestType::TakeKey) {}

protocol::request::RequestFactory::request_ptr
protocol::request::TakeKeyRequestFactory::create() const {
    return std::make_shared<TakeKeyRequest>();
}
