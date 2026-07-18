#pragma once

#include "response-deserialization.hpp"

namespace protocol::deserialization {
    /**
     * @brief Deserializes the response into an object of the GetDataResponse class.
     */
    class GetDataResponseDeserialization final : public ResponseDeserialization {
        response::ResponseFactory::response_ptr
        deserialize_(const serialization::utils::serialize_data_t& data) const override;

    public:
        /**
         * @brief Base constructor.
         */
        GetDataResponseDeserialization();
    };
}  // namespace protocol::deserialization
