#include "response/new-data-response-factory.hpp"

using namespace protocol;

NewDataResponseFactory::NewDataResponseFactory() :
    ResponseFactory(response::ResponseType::NewData) {}

ResponseFactory::response_ptr NewDataResponseFactory::create() {
    return std::make_shared<NewDataResponse>();
}
