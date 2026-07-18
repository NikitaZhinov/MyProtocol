#pragma once

#include "response-factory.hpp"
#include "connect-response.hpp"

namespace protocol::response {
    /**
     * @brief Factory that creates instances of the ConnectResponse class.
     */
    class ConnectResponseFactory final : public ResponseFactory {
    public:
        /**
         * @brief Base constructor.
         */
        ConnectResponseFactory();

        /**
         * @brief Creates an instance of the ConnectResponse class.
         * @return response_ptr
         */
        response_ptr create() const override;

        /**
         * @brief Creates an instance of a ConnectResponse class with parameters.
         * @return request_ptr
         */
        template <class... Args> response_ptr create(Args&&... args) {
            return std::make_shared<ConnectResponse>(std::forward<Args>(args)...);
        }
    };
}  // namespace protocol::response
