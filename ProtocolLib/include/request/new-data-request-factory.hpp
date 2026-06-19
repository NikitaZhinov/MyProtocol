#pragma once

#include "request-factory.hpp"
#include "new-data-request.hpp"

namespace protocol {
    /**
     * @brief Factory that creates instances of the NewDataRequest class.
     */
    class NewDataRequestFactory final : public RequestFactory {
    public:
        /**
         * @brief Base constructor.
         */
        NewDataRequestFactory();

        /**
         * @brief Creates an instance of the NewDataRequest class.
         * @return request_ptr
         */
        request_ptr create() override;

        /**
         * @brief Creates an instance of a NewDataRequest class with parameters.
         * @return request_ptr
         */
        template <class... Args> request_ptr create(Args&&... args) {
            return std::make_shared<NewDataRequest>(std::forward<Args>(args)...);
        }
    };
}  // namespace protocol
