#include "dpp/discord_client.hpp"
#include <iostream>

bool DiscordClient::login(string type, string token) {
    if (token == "" || type == "") {
        std::cerr << "ERROR: Empty token or token type !" << endl;
        return false;
    }
    _dh.add_token(type, token);
    return true;
}

bool DiscordClient::SendMessage(string channel, string content) {
    nlohmann::json message;
    message["content"] = content;
    nlohmann::json response = _dh.post("/channels/440135946801774602/messages", message);
    cout << response.dump();
}

bool DiscordClient::SendEmbed(string channel, RichEmbed embed) {
    nlohmann::json rembed;
    rembed["title"] = embed.title;
    rembed["description"] = embed.title;
    rembed["url"] = embed.title;
    rembed["title"] = embed.title;
    rembed["type"] = "rich";
    nlohmann::json message;
    message["embed"] = rembed.dump();
    nlohmann::json response = _dh.post("/channels/440135946801774602/messages", message);
    cout << "response:" << endl;
    cout << response.dump();
}