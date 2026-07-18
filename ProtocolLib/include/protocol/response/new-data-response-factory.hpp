#pragma once

#include "response-factory.hpp"
#include "new-data-response.hpp"

namespace protocol::response {
    /**
     * @brief Factory that creates instances of the NewDataResponse class.
     */
    class NewDataResponseFactory final : public ResponseFactory {
    public:
        /**
         * @brief Base constructor.
         */
        NewDataResponseFactory();

        /**
         * @brief Creates an instance of the NewDataResponse class.
         * @return response_ptr
         */
        response_ptr create() const override;

        /**
         * @brief Creates an instance of a NewDataResponse class with parameters.
         * @return request_ptr
         */
        template <class... Args> response_ptr create(Args&&... args) {
            return std::make_shared<NewDataResponse>(std::forward<Args>(args)...);
        }
    };
}  // namespace protocol::response
