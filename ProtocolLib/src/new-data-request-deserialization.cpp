#include "protocol/protocol.hpp"

#include <stdexcept>

using protocol::serialization::utils::serialize_data_t;

protocol::deserialization::NewDataRequestDeserialization::
    NewDataRequestDeserialization() :
    RequestDeserialization(request::RequestType::NewData) {}

protocol::request::RequestFactory::request_ptr
protocol::deserialization::NewDataRequestDeserialization::deserialize_(
    const serialize_data_t& data) const {
    serialize_data_t serialized_number(data.begin(), data.begin() + 8);
    serialize_data_t serialized_data(data.begin() + 8, data.end());

    auto number = utils::deserializateNumber(serialized_number);
    auto d_data = utils::deserializateStr(serialized_data);

    request::NewDataRequestFactory factory;

    return factory.create(number, d_data);
}
