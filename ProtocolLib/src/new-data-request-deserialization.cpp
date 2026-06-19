#include "deserialization/new-data-request-deserialization.hpp"

#include "deserialization/utils.hpp"
#include "request/new-data-request-factory.hpp"

#include <stdexcept>

using namespace protocol;

NewDataRequestDeserialization::NewDataRequestDeserialization() :
    RequestDeserialization(request::RequestType::NewData) {}

RequestFactory::request_ptr
NewDataRequestDeserialization::deserialize(const utils::serialize_data_t& data) {
    if (utils::deserializeResponseType(data) != getDeserializationType()) {
        throw std::logic_error("cannot deserializate");
    }

    utils::serialize_data_t serialized_number(data.begin() + 1, data.begin() + 9);
    utils::serialize_data_t serialized_data(data.begin() + 9, data.end());

    auto number = utils::deserializateNumber(serialized_number);
    auto d_data = utils::deserializateStr(serialized_data);

    NewDataRequestFactory factory;

    return factory.create(number, d_data);
}
