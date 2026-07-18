#pragma once

#include "protocol/request/type.hpp"
#include "protocol/response/type.hpp"

#include <string>
#include <vector>

namespace protocol::serialization::utils {
    /**
     * @brief A type for describing serialized data.
     */
    using serialize_data_t = std::vector<std::uint8_t>;

    /**
     * @brief Auxiliary function for serializing RequestType.
     * @param type A RequestType
     * @return serialize_data_t
     */
    serialize_data_t serialize(request::RequestType type);

    /**
     * @brief Auxiliary function for serializing ResponseType.
     * @param type A ResponseType
     * @return serialize_data_t
     */
    serialize_data_t serialize(response::ResponseType type);

    /**
     * @brief Auxiliary function for serializing numbers.
     * @param number A number
     * @return serialize_data_t
     */
    serialize_data_t serialize(std::uint64_t number);

    /**
     * @brief Auxiliary function for serializing strings.
     * @param str A string
     * @return serialize_data_t
     */
    serialize_data_t serialize(const std::string& str);
}  // namespace protocol::serialization::utils
