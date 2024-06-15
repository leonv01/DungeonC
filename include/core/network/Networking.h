//
// Created by leonv on 15.06.2024.
//

#ifndef DUNGEONC_NETWORKING_H
#define DUNGEONC_NETWORKING_H

#include <SFML/Network.hpp>

class Networking {
public:
    Networking();


    void connect();
    void disconnect();
    void send();
    void receive();

private:
    sf::TcpSocket socket;
    sf::IpAddress ip;
    unsigned short port;
};


#endif //DUNGEONC_NETWORKING_H
