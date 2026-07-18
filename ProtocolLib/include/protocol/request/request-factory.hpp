#pragma once

#include "request.hpp"

#include <memory>

namespace protocol::request {
    /**
     * @brief The interface of the factory that produces requests.
     */
    class RequestFactory {
        RequestType creation_type_;

    protected:
        RequestFactory(RequestType creation_type);

    public:
        /**
         * @brief The result of the factory creation.
         */
        using request_ptr = std::shared_ptr<Request>;

        /**
         * @brief Virtual destructor.
         */
        virtual ~RequestFactory() {}

        /**
         * @brief Returns the message type to be created.
         * @return RequestType
         */
        RequestType getCreationType() const;

        /**
         * @brief Creates a request.
         * @return request_ptr
         */
        virtual request_ptr create() const = 0;
    };
}  // namespace protocol::request
