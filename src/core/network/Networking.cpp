//
// Created by leonv on 15.06.2024.
//

#include <iostream>
#include "core/network/Networking.h"

Networking::Networking() {
    ip = "192.168.0.123";
    port = 25565;
}

void Networking::connect() {
    sf::Socket::Status status = socket.connect(ip, port);
    if(status != sf::Socket::Done) {
        // Error handling
    }

    // Send a message to the server
    sf::Packet packet;
    packet << "Hello, server!";
    socket.send(packet);

    // Receive a message from the server
    sf::Packet receivedPacket;
    socket.receive(receivedPacket);

    std::string message;
    receivedPacket >> message;

    std::cout << "Received message from server: " << message << std::endl;

    // Disconnect from the server
    socket.disconnect();
}
