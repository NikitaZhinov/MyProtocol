#include "request/new-data-request-factory.hpp"

#include "request/new-data-request.hpp"

using namespace protocol;

NewDataRequestFactory::NewDataRequestFactory() :
    RequestFactory(request::RequestType::NewData) {}

NewDataRequestFactory::request_ptr NewDataRequestFactory::create() {
    return std::make_shared<NewDataRequest>();
}
