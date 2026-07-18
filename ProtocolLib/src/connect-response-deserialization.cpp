#include "protocol/protocol.hpp"

protocol::response::ResponseFactory::response_ptr
protocol::deserialization::ConnectResponseDeserialization::deserialize_(
    const serialization::utils::serialize_data_t& data) const {
    response::ConnectResponseFactory factory;
    return factory.create(std::vector<std::uint8_t>(data.begin(), data.end()));
}

protocol::deserialization::ConnectResponseDeserialization::
    ConnectResponseDeserialization() :
    ResponseDeserialization(protocol::response::ResponseType::Connect) {}
