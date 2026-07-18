#include "service/serialization-response-service.hpp"

service::SerializationResponseService::SerializationResponseService() {
    serialization_response_strategies_.emplace_back(
        std::make_shared<protocol::serialization::ConnectResponseSerialization>());

    serialization_response_strategies_.emplace_back(
        std::make_shared<protocol::serialization::NewDataResponseSerialization>());

    serialization_response_strategies_.emplace_back(
        std::make_shared<protocol::serialization::GetDataResponseSerialization>());
}

protocol::serialization::utils::serialize_data_t
service::SerializationResponseService::serializationResponse(
    protocol::response::ResponseFactory::response_ptr response) const {
    for (auto& strategy : serialization_response_strategies_) {
        if (strategy->getSerializationType() == response->getType()) {
            return strategy->serialize(response);
        }
    }

    throw std::runtime_error("undefined response type");
}
