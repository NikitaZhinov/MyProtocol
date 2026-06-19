#pragma once

#include "serialization/utils.hpp"
#include "response/response-factory.hpp"

#include <vector>
#include <cstdint>

namespace protocol {
    /**
     * @brief Deserializer interface.
     */
    class ResponseDeserialization {
        response::ResponseType deserialization_type_;

    protected:
        ResponseDeserialization(response::ResponseType deserialization_type);

    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~ResponseDeserialization() {}

        /**
         * @brief Deserializes the response into an object of the class.
         * @param data a serialized response
         * @return ResponseFactory::response_ptr
         */
        virtual ResponseFactory::response_ptr
        deserialize(const utils::serialize_data_t& data) = 0;

        /**
         * @brief Returns a deserialization type.
         * @return response::ResponseType
         */
        response::ResponseType getDeserializationType() const;
    };
}  // namespace protocol
