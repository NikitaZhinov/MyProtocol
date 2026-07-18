#pragma once

#include "protocol/request/request-factory.hpp"
#include "utils.hpp"

#include <vector>
#include <cstdint>

namespace protocol::serialization {
    /**
     * @brief Serializer interface.
     */
    class RequestSerialization {
        request::RequestType serialization_type_;

    protected:
        RequestSerialization(request::RequestType serialization_type);

        virtual utils::serialize_data_t
        serialize_(request::RequestFactory::request_ptr request) const = 0;

    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~RequestSerialization() {}

        /**
         * @brief Serializes the request.
         * @param request A request
         * @return utils::serialize_data_t
         */
        utils::serialize_data_t
        serialize(request::RequestFactory::request_ptr request) const;

        /**
         * @brief Returns serialization type.
         * @return request::RequestType
         */
        request::RequestType getSerializationType() const;
    };
}  // namespace protocol::serialization
