#include "deserialization/get-data-request-deserialization.hpp"

#include "deserialization/utils.hpp"
#include "request/get-data-request-factory.hpp"

#include <stdexcept>

using namespace protocol;

GetDataRequestDeserialization::GetDataRequestDeserialization() :
    RequestDeserialization(request::RequestType::GetData) {}

RequestFactory::request_ptr
GetDataRequestDeserialization::deserialize(const utils::serialize_data_t& data) {
    GetDataRequestFactory factory;

    if (utils::deserializeResponseType(data) != getDeserializationType()) {
        throw std::logic_error("cannot deserializate");
    }

    return factory.create(utils::deserializateNumber(
        utils::serialize_data_t(data.begin() + 1, data.end())));
}
