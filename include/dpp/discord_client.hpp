#include <dpp/discord_http.hpp>
#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;

class DiscordClient {
    public:
        bool login(string type, string token);
    private:
        dpp::discord_http _dh;
};