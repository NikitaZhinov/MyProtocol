#pragma once

#include "request-deserialization.hpp"

namespace protocol::deserialization {
    /**
     * @brief Deserializes the request into an object of the GetDataRequest class.
     */
    class GetDataRequestDeserialization final : public RequestDeserialization {
        request::RequestFactory::request_ptr
        deserialize_(const serialization::utils::serialize_data_t& data) const override;

    public:
        /**
         * @brief Base constructor.
         */
        GetDataRequestDeserialization();
    };
}  // namespace protocol::deserialization
