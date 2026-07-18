#pragma once

#include <protocol/protocol.hpp>

namespace service {
    class SerializationResponseService final {
        std::vector<std::shared_ptr<protocol::serialization::ResponseSerialization>>
            serialization_response_strategies_;

    public:
        SerializationResponseService();

        protocol::serialization::utils::serialize_data_t serializationResponse(
            protocol::response::ResponseFactory::response_ptr response) const;
    };
}  // namespace service
