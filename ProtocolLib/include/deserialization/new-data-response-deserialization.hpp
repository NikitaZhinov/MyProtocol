#pragma once

#include "response-deserialization.hpp"

namespace protocol {
    /**
     * @brief Deserializes the response into an object of the NewDataResponse class.
     */
    class NewDataResponseDeserialization final : public ResponseDeserialization {
    public:
        /**
         * @brief Base constructor.
         */
        NewDataResponseDeserialization();

        /**
         * @brief Deserializes the response into an object of the NewDataResponse class.
         * @param msg the serialized response
         * @return ResponseFactory::response_ptr
         */
        ResponseFactory::response_ptr
        deserialize(const utils::serialize_data_t& data) override;
    };
}  // namespace protocol
