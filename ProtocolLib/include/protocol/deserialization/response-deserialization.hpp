#pragma once

#include "protocol/serialization/utils.hpp"
#include "protocol/response/response-factory.hpp"

#include <vector>
#include <cstdint>

namespace protocol::deserialization {
    /**
     * @brief Deserializer interface.
     */
    class ResponseDeserialization {
        response::ResponseType deserialization_type_;

    protected:
        ResponseDeserialization(response::ResponseType deserialization_type);

        virtual response::ResponseFactory::response_ptr
        deserialize_(const serialization::utils::serialize_data_t& data) const = 0;

    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~ResponseDeserialization() {}

        /**
         * @brief Deserializes the response into an object of the class.
         * @param data A serialized response
         * @return response::ResponseFactory::response_ptr
         */
        response::ResponseFactory::response_ptr
        deserialize(const serialization::utils::serialize_data_t& data) const;

        /**
         * @brief Returns a deserialization type.
         * @return response::ResponseType
         */
        response::ResponseType getDeserializationType() const;
    };
}  // namespace protocol::deserialization
