#pragma once

#include "urler.hpp"
#include <nlohmann/json.hpp>
#include <string>

/*  This class is a wrapper of the lower level urler
    to interface quicker with the discord endpoints */

// This is mostly to be used in the future base_client class

namespace dpp {
  class discord_http {
  private:
    std::string m_token_type;
    std::string m_token;

  public:
    void add_token(std::string t_type, std::string t_token);
    nlohmann::json post(std::string t_endpoint, nlohmann::json t_payload);
    nlohmann::json get(std::string t_endpoint, std::string t_url_encoded);
    // Other methods are to be added

  private:
    void configure_urler_client(dpp::urler* p_u);
  };
}