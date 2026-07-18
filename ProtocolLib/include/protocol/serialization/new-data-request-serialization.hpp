#pragma once

#include "request-serialization.hpp"

namespace protocol::serialization {
    /**
     * @brief Serializes objects of the NewDataRequest class.
     */
    class NewDataRequestSerialization final : public RequestSerialization {
        utils::serialize_data_t
        serialize_(request::RequestFactory::request_ptr request) const override;

    public:
        /**
         * @brief Base constructor.
         */
        NewDataRequestSerialization();
    };
}  // namespace protocol::serialization
