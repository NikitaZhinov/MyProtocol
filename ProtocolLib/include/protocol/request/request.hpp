#pragma once

#include "type.hpp"

#include <string>
#include <string_view>

namespace protocol::request {
    /**
     * @brief Request Interface.
     */
    class Request {
        RequestType type_;

    protected:
        Request(RequestType type);

    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~Request() {}

        /**
         * @brief Returns type.
         * @return RequestType.
         */
        RequestType getType() const;
    };
}  // namespace protocol::request
