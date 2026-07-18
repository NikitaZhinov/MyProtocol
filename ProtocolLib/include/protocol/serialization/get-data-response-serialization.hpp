#pragma once

#include "response-serialization.hpp"

namespace protocol::serialization {
    /**
     * @brief Serializes objects of the GetDataResponse class.
     */
    class GetDataResponseSerialization final : public ResponseSerialization {
        utils::serialize_data_t
        serialize_(response::ResponseFactory::response_ptr response) const override;

    public:
        /**
         * @brief Base constructor.
         */
        GetDataResponseSerialization();
    };
}  // namespace protocol::serialization
