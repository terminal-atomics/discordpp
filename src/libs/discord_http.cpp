#include <dpp/discord_http.hpp>

const std::string discord_url = "discordapp.com";
const std::string discord_api_prefix = "/api";

dpp::discord_http::discord_http() {
    m_u.set_http_ver(11);
    m_u.set_method("GET");
    m_u.set_header("Host", discord_url);
    m_u.set_header("User-Agent", "DiscordBot");
}

nlohmann::json dpp::discord_http::post(std::string t_endpoint, nlohmann::json t_payload) {
    m_u.set_method("POST");
    m_u.set_path(discord_api_prefix + t_endpoint);
    m_u.set_body(t_payload.dump());
    m_u.set_header("Content-Type", "application/json");
    std::string res = m_u.perform(discord_url).body;
    return nlohmann::json::parse(res);
}

nlohmann::json dpp::discord_http::get(std::string t_endpoint, std::string t_url_encoded) {
    m_u.set_method("GET");
    m_u.set_path(discord_api_prefix + t_endpoint);
    m_u.set_body(t_url_encoded);
    m_u.set_header("Content-Type", "application/x-www-form-urlencoded");
    std::string res = m_u.perform(discord_url).body;
    return nlohmann::json::parse(res);
}

// The next method will be for the Base Client when he logs
void dpp::discord_http::add_token(std::string t_type, std::string t_token) {
    m_u.set_header("Authorization", t_type + " " + t_token);
}