#include <dpp/urler.hpp>
#include <iostream>

int main() {
  dpp::urler u;
  u.set_path("/api/gateway");
  u.set_http_ver(11);
  u.set_method("GET");
  u.set_header("Host", "discordapp.com");
  u.set_header("User-Agent", "DiscordBot");
  std::cout << u.perform("discordapp.com").body;
  return 0;
}