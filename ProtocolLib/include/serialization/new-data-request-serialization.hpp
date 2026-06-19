#pragma once

#include "request-serialization.hpp"

namespace protocol {
    /**
     * @brief Serializes objects of the NewDataRequest class.
     */
    class NewDataRequestSerialization final : public RequestSerialization {
    public:
        /**
         * @brief Base constructor.
         */
        NewDataRequestSerialization();

        /**
         * @brief Serializes objects of the NewDataRequest class.
         * @param msg a objects of the NewDataRequest class
         * @return serialize_data_t
         */
        utils::serialize_data_t serialize(RequestFactory::request_ptr msg) override;
    };
}  // namespace protocol
