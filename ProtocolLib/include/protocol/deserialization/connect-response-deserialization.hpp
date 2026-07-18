#pragma once

#include "response-deserialization.hpp"

namespace protocol::deserialization {
    /**
     * @brief Deserializes objects of the ConnectResponse class.
     */
    class ConnectResponseDeserialization final : public ResponseDeserialization {
        response::ResponseFactory::response_ptr
        deserialize_(const serialization::utils::serialize_data_t& data) const override;

    public:
        /**
         * @brief Base constructor.
         */
        ConnectResponseDeserialization();
    };
}  // namespace protocol::deserialization
