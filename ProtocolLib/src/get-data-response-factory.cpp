#include "response/get-data-response-factory.hpp"

using namespace protocol;

GetDataResponseFactory::GetDataResponseFactory() :
    ResponseFactory(response::ResponseType::GetData) {}

ResponseFactory::response_ptr GetDataResponseFactory::create() {
    return std::make_shared<GetDataResponse>();
}
