#pragma once

#include "response-factory.hpp"
#include "get-data-response.hpp"

namespace protocol {
    /**
     * @brief Factory that creates instances of the GetDataResponse class.
     */
    class GetDataResponseFactory final : public ResponseFactory {
    public:
        /**
         * @brief Base constructor.
         */
        GetDataResponseFactory();

        /**
         * @brief Creates an instance of the GetDataResponse class.
         * @return response_ptr
         */
        response_ptr create() override;

        /**
         * @brief Creates an instance of a GetDataResponse class with parameters.
         * @return request_ptr
         */
        template <class... Args> response_ptr create(Args&&... args) {
            return std::make_shared<GetDataResponse>(std::forward<Args>(args)...);
        }
    };
}  // namespace protocol
