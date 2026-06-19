#pragma once

#include "response-serialization.hpp"

namespace protocol {
    /**
     * @brief Serializes objects of the GetDataResponse class.
     */
    class GetDataResponseSerialization final : public ResponseSerialization {
    public:
        /**
         * @brief Base constructor.
         */
        GetDataResponseSerialization();

        /**
         * @brief Serializes objects of the GetDataResponse class.
         * @param msg a objects of the GetDataResponse class
         * @return serialize_data_t
         */
        utils::serialize_data_t serialize(ResponseFactory::response_ptr msg) override;
    };
}  // namespace protocol
