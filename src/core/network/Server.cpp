//
// Created by leonv on 15.06.2024.
//

#include <iostream>
#include "core/network/Server.h"
#include "core/network/PacketTypes.h"
#include "entity/Player.h"
#include "core/World.h"

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
        sendUpdates();
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
                PacketType type;
                packet >> type;

                Player player = *World::player;
                switch(type){
                    case PacketType::PLAYER_INPUT:
                        player.deserialize(packet);
                        std::cout << "Received player input from client!" << std::endl;
                        std::cout << "Player position: " << player.getX() << ", " << player.getY() << std::endl;
                        break;
                    default:
                        std::cout << "Received unknown packet from client!" << std::endl;
                        break;
                }
            }
        }
    }
}

void Server::sendUpdates() {
    for(auto& client : clients){
        sf::Packet packet;
        packet << "Hello, client!";
        client->send(packet);
    }
}