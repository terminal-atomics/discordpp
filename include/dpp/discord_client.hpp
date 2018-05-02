#include <dpp/discord_http.hpp>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;

class RichEmbed {
    public:
        string title;
        string description;
        string url;
        int color;
};

class DiscordClient {
    public:
        bool login(string type, string token);
        bool SendMessage(string channel, string content);
        bool SendEmbed(string channel, RichEmbed embed);
    private:
        dpp::discord_http _dh;
};
