#include "request/get-data-request-factory.hpp"

#include "request/get-data-request.hpp"

using namespace protocol;

GetDataRequestFactory::GetDataRequestFactory() :
    RequestFactory(request::RequestType::GetData) {}

GetDataRequestFactory::request_ptr GetDataRequestFactory::create() {
    return std::make_shared<GetDataRequest>();
}
