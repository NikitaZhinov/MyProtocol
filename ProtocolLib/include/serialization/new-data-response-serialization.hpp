#pragma once

#include "response-serialization.hpp"

namespace protocol {
    /**
     * @brief Serializes objects of the NewDataResponse class.
     */
    class NewDataResponseSerialization final : public ResponseSerialization {
    public:
        /**
         * @brief Base constructor.
         */
        NewDataResponseSerialization();

        /**
         * @brief Serializes objects of the NewDataResponse class.
         * @param msg a objects of the NewDataResponse class
         * @return serialize_data_t
         */
        utils::serialize_data_t serialize(ResponseFactory::response_ptr msg) override;
    };
}  // namespace protocol
