#pragma once

#include "response/response-factory.hpp"
#include "utils.hpp"

#include <vector>
#include <cstdint>

namespace protocol {
    /**
     * @brief Serializer interface.
     */
    class ResponseSerialization {
        response::ResponseType serialization_type_;

    protected:
        ResponseSerialization(response::ResponseType serialization_type);

    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~ResponseSerialization() {}

        /**
         * @brief Serializes the response.
         * @param response a response
         * @return serialize_data_t
         */
        virtual utils::serialize_data_t
        serialize(ResponseFactory::response_ptr response) = 0;

        /**
         * @brief Returns serialization type.
         * @return response::ResponseType
         */
        response::ResponseType getSerializationType() const;
    };
}  // namespace protocol
