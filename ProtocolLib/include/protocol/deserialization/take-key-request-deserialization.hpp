#pragma once

#include "request-deserialization.hpp"

namespace protocol::deserialization {
    /**
     * @brief Deserializes objects of the TakeKeyRequest class.
     */
    class TakeKeyRequestDeserialization final : public RequestDeserialization {
        request::RequestFactory::request_ptr deserialize_(
            const serialization::utils::serialize_data_t& data) const override;

    public:
        /**
         * @brief Base constructor.
         */
        TakeKeyRequestDeserialization();
    };
}  // namespace protocol::deserialization
