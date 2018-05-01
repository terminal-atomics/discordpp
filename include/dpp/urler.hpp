#pragma once

// Ok this is a http client thing with Boost.Asio
#include <nlohmann/json.hpp>
#include "root_certificates.hpp"
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>
#include "http_res.hpp"

using json = nlohmann::json;

namespace dpp {
    class urler {
        private:
            std::string m_method;
            unsigned int m_http_ver;
            std::string m_path;
            std::string m_body;
            json m_headers;
    
        public:
            urler();
            void set_method(std::string t_method);
            void set_http_ver(unsigned int t_http_ver);
            void set_path(std::string t_path);
            void set_body(std::string t_body);
            void set_header(std::string t_header, std::string t_value);
            void delete_header(std::string t_header);
            http_res perform(std::string t_url);
    };
}
