#include <dpp/discord_http.hpp>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>
#include <dpp/discord_client.hpp>

int main() {
    DiscordClient client;
    client.login("Bot", "NDQwOTk4MDYwNjQ3MjUxOTY4.Dcp-dg.00z0ExWE-Jmxk9nMzP2uRR1iJ9A");
    client.SendMessage("370015453176922122", "Yay, DiscordClient class works !");
    RichEmbed embed;
    embed.title = "Test title";
    embed.description = "Test description";
    embed.url = "https://www.google.com/";
    client.SendEmbed("370015453176922122", embed);
    getchar();
    return 0;
}