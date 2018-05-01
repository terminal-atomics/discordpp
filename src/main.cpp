#include <dpp/discord_http.hpp>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

int main() {
  dpp::discord_http dh;
  dh.add_token("Bot", "");
  nlohmann::json message;
  message["content"] = "Message sent from C++";
  nlohmann::json j = dh.post("/channels/418390319659483137/messages", message);
  std::cout << j.dump();
  return 0;
}