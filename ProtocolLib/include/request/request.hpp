#pragma once

#include "type.hpp"

#include <string>
#include <string_view>

namespace protocol {
    /**
     * @brief Request Interface.
     */
    class Request {
        request::RequestType type_;

    protected:
        Request(request::RequestType type);

    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~Request() {}

        /**
         * @brief Returns type.
         * @return RequestType.
         */
        request::RequestType getType() const;
    };
}  // namespace protocol
