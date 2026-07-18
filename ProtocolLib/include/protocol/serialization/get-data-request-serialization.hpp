#pragma once

#include "request-serialization.hpp"

namespace protocol::serialization {
    /**
     * @brief Serializes objects of the GetDataRequest class.
     */
    class GetDataRequestSerialization final : public RequestSerialization {
        utils::serialize_data_t
        serialize_(request::RequestFactory::request_ptr request) const override;

    public:
        /**
         * @brief Base constructor.
         */
        GetDataRequestSerialization();
    };
}  // namespace protocol::serialization
