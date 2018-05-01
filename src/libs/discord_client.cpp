#include "dpp/discord_client.hpp"
#include <iostream>

bool DiscordClient::login(string type, string token) {
    if (token == "" || type == "") {
        std::cerr << "ERROR: Empty token or token type !" << endl;
        return false;
    }
    _dh.add_token(type, token);
}