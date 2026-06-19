#pragma once

#include "serialization/utils.hpp"
#include "request/request-factory.hpp"

#include <vector>
#include <cstdint>

namespace protocol {
    /**
     * @brief Deserializer interface.
     */
    class RequestDeserialization {
        request::RequestType deserialization_type_;

    protected:
        RequestDeserialization(request::RequestType deserialization_type);

    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~RequestDeserialization() {}

        /**
         * @brief Deserializes the request into an object of the class.
         * @param data a serialized request
         * @return RequestFactory::request_ptr
         */
        virtual RequestFactory::request_ptr
        deserialize(const utils::serialize_data_t& data) = 0;

        /**
         * @brief Returns a deserialization type.
         * @return request::RequestType
         */
        request::RequestType getDeserializationType() const;
    };
}  // namespace protocol
