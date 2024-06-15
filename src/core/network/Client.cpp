//
// Created by leonv on 15.06.2024.
//

#include <iostream>
#include "core/network/Client.h"

Client::Client(const std::string &host, unsigned short port) : host(host), port(port) {
    if(socket.connect(host, port) == sf::Socket::Done){
        selector.add(socket);
        std::cout << "Connected to server!" << std::endl;
    }
}

void Client::run() {
    running = true;
    while(running){
        if(selector.wait()) {
            if (selector.isReady(socket)) {
                receiveUpdates();
            }
        }
        sendInput();
    }
}

void Client::stop() {
    running = false;
}

void Client::sendInput() {
    std::string input;
    std::cout << "Enter a message: ";
    std::getline(std::cin, input);

    sf::Packet packet;
    packet << input;
    socket.send(packet);
}

void Client::receiveUpdates() {
    sf::Packet packet;
    if(socket.receive(packet) == sf::Socket::Done){
        std::string message;
        packet >> message;
        std::cout << "Received message from server: " << message << std::endl;
    }
}