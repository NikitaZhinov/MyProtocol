#include "response/get-data-response.hpp"

using namespace protocol;

GetDataResponse::GetDataResponse() : Response(response::ResponseType::GetData) {}

GetDataResponse::GetDataResponse(
    const std::vector<std::pair<std::uint64_t, std::string>>& data) :
    GetDataResponse() {
    setData(data);
}

void GetDataResponse::setData(
    const std::vector<std::pair<std::uint64_t, std::string>>& data) {
    amount_data_ = data.size();

    for (auto& pair : data) {
        ids_.push_back(pair.first);
        data_.push_back(pair.second);
    }
}

std::size_t GetDataResponse::getAmountData() const {
    return amount_data_;
}

std::vector<std::uint64_t> GetDataResponse::getDataIds() const {
    return ids_;
}

std::vector<std::string> GetDataResponse::getData() const {
    return data_;
}
