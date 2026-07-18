#pragma once

#include "response.hpp"

#include <memory>

namespace protocol::response {
    /**
     * @brief The interface of the factory that produces responses.
     */
    class ResponseFactory {
        ResponseType creation_type_;

    protected:
        ResponseFactory(ResponseType creation_type);

    public:
        /**
         * @brief The result of the factory creation.
         */
        using response_ptr = std::shared_ptr<Response>;

        /**
         * @brief Virtual destructor.
         */
        virtual ~ResponseFactory() {}

        /**
         * @brief Returns the message type to be created.
         * @return ResponseType
         */
        ResponseType getCreationType() const;

        /**
         * @brief Creates a response.
         * @return response_ptr
         */
        virtual response_ptr create() const = 0;
    };
}  // namespace protocol::response
