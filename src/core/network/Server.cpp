//
// Created by leonv on 15.06.2024.
//

#include <iostream>
#include "core/network/Server.h"
#include "core/network/PacketTypes.h"
#include "entity/Player.h"
#include "core/World.h"
#include "core/Game.h"

Server::Server(unsigned int port) : port(port) {
    listener.listen(port);
    selector.add(listener);
}

void Server::run() {
    running = true;
    while(Game::isRunning()){
        if(selector.wait()){
            if(selector.isReady(listener)){
                acceptClients();
            }
            else {
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

        World::players.push_back(Player{{200,200}, {1,1}, 1});
        std::cout << "Player added!" << std::endl;
    }
    else if(listener.accept(*client) == sf::Socket::Disconnected || listener.accept(*client) == sf::Socket::Error){
        World::players.pop_back();
        std::cout << "Player removed!" << std::endl;
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

                switch(type){
                    case PacketType::PLAYER_INPUT:
                        if(!World::players.empty()){
                            World::players[0].deserialize(packet);
                        }

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
        packet << PacketType::PLAYER_UPDATE;
        World::player->serialize(packet);

        client->send(packet);
    }
}