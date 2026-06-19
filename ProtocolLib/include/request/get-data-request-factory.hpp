#pragma once

#include "request-factory.hpp"
#include "get-data-request.hpp"

namespace protocol {
    /**
     * @brief Factory that creates instances of the GetDataRequest class.
     */
    class GetDataRequestFactory final : public RequestFactory {
    public:
        /**
         * @brief Base constructor.
         */
        GetDataRequestFactory();

        /**
         * @brief Creates an instance of the GetDataRequest class.
         * @return request_ptr
         */
        request_ptr create() override;

        /**
         * @brief Creates an instance of a GetDataRequest class with parameters.
         * @return request_ptr
         */
        template <class... Args> request_ptr create(Args&&... args) {
            return std::make_shared<GetDataRequest>(std::forward<Args>(args)...);
        }
    };
}  // namespace protocol
