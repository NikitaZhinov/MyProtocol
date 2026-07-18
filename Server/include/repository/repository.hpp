#pragma once

#include "model/data-model.hpp"

#include <boost/asio.hpp>
#include <boost/mysql.hpp>

namespace repository {
    class Repository {
        boost::mysql::any_connection connection_;
        std::string table_name_;

    public:
        Repository(boost::asio::io_context& ctx, const std::string_view& hostname,
                   const std::string_view& username, const std::string_view& password,
                   const std::string_view& database, const std::string_view& table_name);

        virtual ~Repository();

        std::uint64_t add(std::uint64_t user_id, const std::string_view& data);

        std::vector<model::DataModel> getUserData(std::uint64_t user_id);
    };
}  // namespace repository
