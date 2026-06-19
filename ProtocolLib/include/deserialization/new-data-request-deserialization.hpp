#pragma once

#include "request-deserialization.hpp"

namespace protocol {
    /**
     * @brief Deserializes the request into an object of the NewDataRequest class.
     */
    class NewDataRequestDeserialization final : public RequestDeserialization {
    public:
        /**
         * @brief Base constructor.
         */
        NewDataRequestDeserialization();

        /**
         * @brief Deserializes the request into an object of the NewDataRequest class.
         * @param msg the serialized request
         * @return RequestFactory::request_ptr
         */
        RequestFactory::request_ptr
        deserialize(const utils::serialize_data_t& data) override;
    };
}  // namespace protocol
