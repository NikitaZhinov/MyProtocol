#include "protocol/protocol.hpp"

#include <stdexcept>

using protocol::serialization::utils::serialize_data_t;

protocol::deserialization::GetDataResponseDeserialization::
    GetDataResponseDeserialization() :
    ResponseDeserialization(response::ResponseType::GetData) {}

protocol::response::ResponseFactory::response_ptr
protocol::deserialization::GetDataResponseDeserialization::deserialize_(
    const serialize_data_t& data) const {
    serialize_data_t serialize_amount(data.begin(), data.begin() + 8);

    std::size_t amount = utils::deserializateNumber(serialize_amount);

    std::vector<std::uint64_t> ids;

    for (std::size_t i = 0; i < amount; ++i) {
        serialize_data_t serialize_id(data.begin() + 8 * (i + 1),
                                      data.begin() + 8 * (i + 2));

        ids.push_back(utils::deserializateNumber(serialize_id));
    }

    std::vector<std::string> user_data;
    std::size_t j = (amount + 1) * 8;

    for (std::size_t i = 0; i < amount; ++i) {
        serialize_data_t cur_data;

        while (data[j] != '\0') {
            cur_data.push_back(data[j++]);
        }
        ++j;

        user_data.push_back(utils::deserializateStr(cur_data));
    }

    std::vector<std::pair<std::uint64_t, std::string>> deserialize_data(amount);

    for (std::size_t i = 0; i < amount; ++i) {
        deserialize_data[i].first = ids[i];
        deserialize_data[i].second = user_data[i];
    }

    response::GetDataResponseFactory factory;

    return factory.create(deserialize_data);
}
