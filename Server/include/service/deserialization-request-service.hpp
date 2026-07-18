#pragma once

#include <protocol/protocol.hpp>

namespace service {
    class DeserializationRequestService final {
        std::vector<std::shared_ptr<protocol::deserialization::RequestDeserialization>>
            deserialization_request_strategies_;

    public:
        DeserializationRequestService();

        protocol::request::RequestFactory::request_ptr deserializationRequest(
            const protocol::serialization::utils::serialize_data_t& data) const;
    };
}  // namespace service
