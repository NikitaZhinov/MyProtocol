#pragma once

#include "request-serialization.hpp"

namespace protocol {
    /**
     * @brief Serializes objects of the GetDataRequest class.
     */
    class GetDataRequestSerialization final : public RequestSerialization {
    public:
        /**
         * @brief Base constructor.
         */
        GetDataRequestSerialization();

        /**
         * @brief Serializes objects of the GetDataRequest class.
         * @param msg a objects of the GetDataRequest class
         * @return serialize_data_t
         */
        utils::serialize_data_t serialize(RequestFactory::request_ptr msg) override;
    };
}  // namespace protocol
