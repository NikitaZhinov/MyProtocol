#include "protocol/protocol.hpp"

#include <stdexcept>

using protocol::serialization::utils::serialize_data_t;

protocol::deserialization::NewDataResponseDeserialization::
    NewDataResponseDeserialization() :
    ResponseDeserialization(response::ResponseType::NewData) {}

protocol::response::ResponseFactory::response_ptr
protocol::deserialization::NewDataResponseDeserialization::deserialize_(
    const serialize_data_t& data) const {
    response::NewDataResponseFactory factory;

    return factory.create(
        utils::deserializateNumber(serialize_data_t(data.begin(), data.end())));
}
