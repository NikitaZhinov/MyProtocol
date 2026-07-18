#include "protocol/protocol.hpp"

protocol::request::RequestFactory::request_ptr
protocol::deserialization::TakeKeyRequestDeserialization::deserialize_(
    const serialization::utils::serialize_data_t& data) const {
    request::TakeKeyRequestFactory factory;
    return factory.create(std::vector<std::uint8_t>(data.begin(), data.end()));
}

protocol::deserialization::TakeKeyRequestDeserialization::
    TakeKeyRequestDeserialization() :
    RequestDeserialization(protocol::request::RequestType::TakeKey) {}
