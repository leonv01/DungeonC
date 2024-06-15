//
// Created by leonv on 15.06.2024.
//

#include <iostream>
#include "core/network/Server.h"

Server::Server(unsigned int port) : port(port) {
    listener.listen(port);
    selector.add(listener);
}

void Server::run() {
    running = true;
    while(running){
        if(selector.wait()){
            if(selector.isReady(listener)){
                acceptClients();
            } else {
                receivePackets();
            }
        }
        sendPackets();
    }
}

void Server::stop() {
    running = false;
}

void Server::acceptClients() {
    std::unique_ptr<sf::TcpSocket> client = std::make_unique<sf::TcpSocket>();
    if(listener.accept(*client) == sf::Socket::Done){
        clients.push_back(std::move(client));
        selector.add(*clients.back());
        std::cout << "Client connected!" << std::endl;
    }
    else {
        client.reset();
        std::cout << "Error while accepting client!" << std::endl;
    }
}

void Server::receivePackets() {
    for(auto& client : clients){
        if(selector.isReady(*client)){
            sf::Packet packet;
            if(client->receive(packet) == sf::Socket::Done){
                std::string message;
                packet >> message;
                std::cout << "Received message: " << message << std::endl;
            }
        }
    }
}

void Server::sendPackets() {
    for(auto& client : clients){
        sf::Packet packet;
        packet << "Hello, client!";
        client->send(packet);
    }
}