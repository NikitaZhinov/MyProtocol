#pragma once

#include "type.hpp"

#include <string>
#include <string_view>

namespace protocol::response {
    /**
     * @brief Response Interface.
     */
    class Response {
        ResponseType type_;

    protected:
        Response(ResponseType type);

    public:
        /**
         * @brief Virtual destructor.
         */
        virtual ~Response() {}

        /**
         * @brief Returns type.
         * @return ResponseType.
         */
        ResponseType getType() const;
    };
}  // namespace protocol::response
