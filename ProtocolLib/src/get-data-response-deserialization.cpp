#include "deserialization/get-data-response-deserialization.hpp"

#include "deserialization/utils.hpp"
#include "response/get-data-response-factory.hpp"

#include <stdexcept>

using namespace protocol;

GetDataResponseDeserialization::GetDataResponseDeserialization() :
    ResponseDeserialization(response::ResponseType::GetData) {}

ResponseFactory::response_ptr
GetDataResponseDeserialization::deserialize(const utils::serialize_data_t& data) {
    if (utils::deserializeResponseType(data) != getDeserializationType()) {
        throw std::logic_error("cannot deserializate");
    }

    utils::serialize_data_t serialize_amount(data.begin() + 1, data.begin() + 9);

    std::size_t amount = utils::deserializateNumber(serialize_amount);

    std::vector<std::uint64_t> ids;

    for (std::size_t i = 0; i < amount; ++i) {
        utils::serialize_data_t serialize_id(data.begin() + 1 + 8 * (i + 1),
                                             data.begin() + 1 + 8 * (i + 2));

        ids.push_back(utils::deserializateNumber(serialize_id));
    }

    std::vector<std::string> user_data;
    std::size_t j = (amount + 1) * 8 + 1;

    for (std::size_t i = 0; i < amount; ++i) {
        utils::serialize_data_t cur_data;

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

    GetDataResponseFactory factory;

    return factory.create(deserialize_data);
}
