//
// Created by leonv on 15.06.2024.
//

#ifndef DUNGEONC_SERVER_H
#define DUNGEONC_SERVER_H

#include <SFML/Network.hpp>
#include <vector>
#include <string>
#include <memory>

class Server {
public:
    Server(unsigned int port);
    void run();
    void stop();

private:
    void acceptClients();
    void receivePackets();
    void sendPackets();

    sf::TcpListener listener;
    std::vector<std::unique_ptr<sf::TcpSocket>> clients;
    sf::SocketSelector selector;
    bool running = false;
    unsigned int port;
};


#endif //DUNGEONC_SERVER_H
