#pragma once

#include "response-serialization.hpp"

namespace protocol::serialization {
    /**
     * @brief Serializes objects of the ConnectResponse class.
     */
    class ConnectResponseSerialization final : public ResponseSerialization {
        utils::serialize_data_t
        serialize_(response::ResponseFactory::response_ptr response) const override;

    public:
        /**
         * @brief Base constructor.
         */
        ConnectResponseSerialization();
    };
}  // namespace protocol::serialization
