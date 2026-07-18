#pragma once

#include "request-deserialization.hpp"

namespace protocol::deserialization {
    /**
     * @brief Deserializes the request into an object of the NewDataRequest class.
     */
    class NewDataRequestDeserialization final : public RequestDeserialization {
        request::RequestFactory::request_ptr
        deserialize_(const serialization::utils::serialize_data_t& data) const override;

    public:
        /**
         * @brief Base constructor.
         */
        NewDataRequestDeserialization();
    };
}  // namespace protocol::deserialization
