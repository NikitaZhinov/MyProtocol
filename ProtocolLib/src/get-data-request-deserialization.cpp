#include "protocol/protocol.hpp"

#include <stdexcept>

using protocol::serialization::utils::serialize_data_t;

protocol::deserialization::GetDataRequestDeserialization::
    GetDataRequestDeserialization() :
    RequestDeserialization(request::RequestType::GetData) {}

protocol::request::RequestFactory::request_ptr
protocol::deserialization::GetDataRequestDeserialization::deserialize_(
    const serialize_data_t& data) const {
    request::GetDataRequestFactory factory;
    return factory.create(
        utils::deserializateNumber(serialize_data_t(data.begin(), data.end())));
}
