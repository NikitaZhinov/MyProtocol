#include "service/deserialization-request-service.hpp"

service::DeserializationRequestService::DeserializationRequestService() {
    deserialization_request_strategies_.emplace_back(
        std::make_shared<protocol::deserialization::TakeKeyRequestDeserialization>());

    deserialization_request_strategies_.emplace_back(
        std::make_shared<protocol::deserialization::NewDataRequestDeserialization>());

    deserialization_request_strategies_.emplace_back(
        std::make_shared<protocol::deserialization::GetDataRequestDeserialization>());
}

protocol::request::RequestFactory::request_ptr
service::DeserializationRequestService::deserializationRequest(
    const protocol::serialization::utils::serialize_data_t& data) const {
    for (auto& strategy : deserialization_request_strategies_) {
        if (strategy->getDeserializationType() ==
            protocol::deserialization::utils::deserializeRequestType(data)) {
            return strategy->deserialize(data);
        }
    }

    throw std::runtime_error("undefined request type");
}
