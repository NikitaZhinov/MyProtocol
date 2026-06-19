#pragma once

#include "request/request-factory.hpp"
#include "utils.hpp"

#include <vector>
#include <cstdint>

namespace protocol {
    /**
     * @brief Serializer interface.
     */
    class RequestSerialization {
        request::RequestType serialization_type_;

    protected:
        RequestSerialization(request::RequestType serialization_type);

    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~RequestSerialization() {}

        /**
         * @brief Serializes the request.
         * @param request a request
         * @return serialize_data_t
         */
        virtual utils::serialize_data_t
        serialize(RequestFactory::request_ptr request) = 0;

        /**
         * @brief Returns serialization type.
         * @return request::RequestType
         */
        request::RequestType getSerializationType() const;
    };
}  // namespace protocol
