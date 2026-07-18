#pragma once

#include "request-factory.hpp"
#include "take-key-request.hpp"

namespace protocol::request {
    /**
     * @brief Factory that creates instances of the TakeKeyRequest class.
     */
    class TakeKeyRequestFactory final : public RequestFactory {
    public:
        /**
         * @brief Base constructor.
         */
        TakeKeyRequestFactory();

        /**
         * @brief Creates an instance of the TakeKeyRequest class.
         * @return request_ptr
         */
        request_ptr create() const override;

        /**
         * @brief Creates an instance of a TakeKeyRequest class with parameters.
         * @return request_ptr
         */
        template <class... Args> request_ptr create(Args&&... args) {
            return std::make_shared<TakeKeyRequest>(std::forward<Args>(args)...);
        }
    };
}  // namespace protocol::request
