#pragma once

#include "protocol/serialization/utils.hpp"
#include "protocol/request/request-factory.hpp"

#include <vector>
#include <cstdint>

namespace protocol::deserialization {
    /**
     * @brief Deserializer interface.
     */
    class RequestDeserialization {
        request::RequestType deserialization_type_;

    protected:
        RequestDeserialization(request::RequestType deserialization_type);

        virtual request::RequestFactory::request_ptr
        deserialize_(const serialization::utils::serialize_data_t& data) const = 0;

    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~RequestDeserialization() {}

        /**
         * @brief Deserializes the request into an object of the class.
         * @param data A serialized request
         * @return request::RequestFactory::request_ptr
         */
        request::RequestFactory::request_ptr
        deserialize(const serialization::utils::serialize_data_t& data) const;

        /**
         * @brief Returns a deserialization type.
         * @return request::RequestType
         */
        request::RequestType getDeserializationType() const;
    };
}  // namespace protocol::deserialization
