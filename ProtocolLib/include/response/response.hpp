#pragma once

#include "type.hpp"

#include <string>
#include <string_view>

namespace protocol {
    /**
     * @brief Response Interface.
     */
    class Response {
        response::ResponseType type_;

    protected:
        Response(response::ResponseType type);

    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~Response() {}

        /**
         * @brief Returns type.
         * @return ResponseType.
         */
        response::ResponseType getType() const;
    };
}  // namespace protocol
