#pragma once

#include "response-deserialization.hpp"

namespace protocol {
    /**
     * @brief Deserializes the response into an object of the GetDataResponse class.
     */
    class GetDataResponseDeserialization final : public ResponseDeserialization {
    public:
        /**
         * @brief Base constructor.
         */
        GetDataResponseDeserialization();

        /**
         * @brief Deserializes the response into an object of the GetDataResponse class.
         * @param msg the serialized response
         * @return ResponseFactory::response_ptr
         */
        ResponseFactory::response_ptr
        deserialize(const utils::serialize_data_t& data) override;
    };
}  // namespace protocol
