#pragma once

#include "protocol/response/response-factory.hpp"
#include "utils.hpp"

#include <vector>
#include <cstdint>

namespace protocol::serialization {
    /**
     * @brief Serializer interface.
     */
    class ResponseSerialization {
        response::ResponseType serialization_type_;

    protected:
        ResponseSerialization(response::ResponseType serialization_type);

        virtual utils::serialize_data_t
        serialize_(response::ResponseFactory::response_ptr response) const = 0;

    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~ResponseSerialization() {}

        /**
         * @brief Serializes the response.
         * @param response A response
         * @return utils::serialize_data_t
         */
        utils::serialize_data_t
        serialize(response::ResponseFactory::response_ptr response) const;

        /**
         * @brief Returns serialization type.
         * @return response::ResponseType
         */
        response::ResponseType getSerializationType() const;
    };
}  // namespace protocol::serialization
