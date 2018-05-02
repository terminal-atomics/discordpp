#include <dpp/discord_http.hpp>
#include <dpp/discord_api_ep.hpp>


void dpp::discord_http::configure_urler_client(dpp::urler* p_u) {
  p_u->set_http_ver(11);
  p_u->set_method("GET");
  p_u->set_header("Host", api::DISCORD_URL);
  p_u->set_header("User-Agent", "DiscordBot");
  if (m_token_type != "" && m_token != "") {
    p_u->set_header("Authorization", m_token_type + " " + m_token);
  }
}

nlohmann::json dpp::discord_http::post(std::string t_endpoint, nlohmann::json t_payload) {
  urler u;
  configure_urler_client(&u);
  u.set_method("POST");
  u.set_path(api::DISCORD_API_PREFIX + t_endpoint);
  u.set_body(t_payload.dump());
  u.set_header("Content-Type", "application/json");
  std::string res = u.perform(api::DISCORD_URL).body;
  return nlohmann::json::parse(res);
}

nlohmann::json dpp::discord_http::get(std::string t_endpoint, std::string t_url_encoded) {
  urler u;
  configure_urler_client(&u);
  u.set_method("GET");
  u.set_path(api::DISCORD_API_PREFIX + t_endpoint);
  u.set_body(t_url_encoded);
  u.set_header("Content-Type", "application/x-www-form-urlencoded");
  std::string res = u.perform(api::DISCORD_URL).body;
  return nlohmann::json::parse(res);
}

// The next method will be for the Base Client when he logs
void dpp::discord_http::add_token(std::string t_type, std::string t_token) {
  m_token_type = t_type;
  m_token = t_token;
}