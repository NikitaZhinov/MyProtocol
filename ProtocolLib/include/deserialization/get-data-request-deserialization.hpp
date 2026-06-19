#pragma once

#include "request-deserialization.hpp"

namespace protocol {
    /**
     * @brief Deserializes the request into an object of the GetDataRequest class.
     */
    class GetDataRequestDeserialization final : public RequestDeserialization {
    public:
        /**
         * @brief Base constructor.
         */
        GetDataRequestDeserialization();

        /**
         * @brief Deserializes the request into an object of the GetDataRequest class.
         * @param msg the serialized request
         * @return RequestFactory::request_ptr
         */
        RequestFactory::request_ptr
        deserialize(const utils::serialize_data_t& data) override;
    };
}  // namespace protocol
