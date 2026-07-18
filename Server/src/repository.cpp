#include "repository/repository.hpp"

namespace mysql = boost::mysql;

repository::Repository::Repository(boost::asio::io_context& ctx,
                                   const std::string_view& hostname,
                                   const std::string_view& username,
                                   const std::string_view& password,
                                   const std::string_view& database,
                                   const std::string_view& table_name) :
    connection_(ctx),
    table_name_(table_name) {
    mysql::connect_params params;

    params.server_address.emplace_host_and_port(hostname.data());
    params.username = username;
    params.password = password;
    params.database = database;

    connection_.connect(params);
}

repository::Repository::~Repository() {
    connection_.close();
}

std::uint64_t repository::Repository::add(std::uint64_t user_id,
                                          const std::string_view& data) {
    mysql::results res;

    connection_.execute(
        mysql::with_params("INSERT INTO data (userId, data) VALUES ({}, {})", user_id,
                           data),
        res);

    return res.last_insert_id();
}

std::vector<model::DataModel> repository::Repository::getUserData(std::uint64_t user_id) {
    mysql::results sql_res;
    connection_.execute(
        mysql::with_params("SELECT * FROM data WHERE userId = {}", user_id), sql_res);

    std::vector<model::DataModel> res;

    auto rows = sql_res.rows();

    for (auto it = rows.begin(), it_end = rows.end(); it != it_end; ++it) {
        auto row = it->as_vector();
        res.emplace_back(row[0].as_uint64(), row[1].as_uint64(), row[2].as_string());
    }

    return res;
}
