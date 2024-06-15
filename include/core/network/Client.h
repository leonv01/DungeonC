//
// Created by leonv on 15.06.2024.
//

#ifndef DUNGEONC_CLIENT_H
#define DUNGEONC_CLIENT_H

#include "SFML/Network.hpp"

class Client {
public:
    Client(const std::string& host, unsigned short port);
    void run();
    void stop();

private:
    void sendInput();
    void receiveUpdates();

    sf::TcpSocket socket;
    sf::SocketSelector selector;
    bool running = false;
    std::string host;
    unsigned short port;
};


#endif //DUNGEONC_CLIENT_H
