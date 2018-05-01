#include <dpp/discord_http.hpp>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <dpp/discord_client.hpp>

int main() {
    DiscordClient client;
    client.login("Bot", "");
    return 0;
}