#include "deserialization/new-data-response-deserialization.hpp"

#include "response/new-data-response-factory.hpp"
#include "deserialization/utils.hpp"

#include <stdexcept>

using namespace protocol;

NewDataResponseDeserialization::NewDataResponseDeserialization() :
    ResponseDeserialization(response::ResponseType::NewData) {}

ResponseFactory::response_ptr
NewDataResponseDeserialization::deserialize(const utils::serialize_data_t& data) {
    NewDataResponseFactory factory;

    if (utils::deserializeResponseType(data) != getDeserializationType()) {
        throw std::logic_error("cannot deserializate");
    }

    return factory.create(utils::deserializateNumber(
        utils::serialize_data_t(data.begin() + 1, data.end())));
}
