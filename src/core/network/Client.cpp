//
// Created by leonv on 15.06.2024.
//

#include <iostream>
#include "core/network/Client.h"
#include "core/network/PacketTypes.h"
#include "entity/Player.h"
#include "core/World.h"
#include "core/Game.h"

Client::Client(const std::string &host, unsigned short port) : host(host), port(port) {
    if(socket.connect(host, port) == sf::Socket::Done){
        selector.add(socket);
        std::cout << "Connected to server!" << std::endl;
        World::players.push_back(Player{{0,0}, {1,1}, 1});
    }
}

void Client::run() {

    while(Game::isRunning()){
        if(selector.wait()) {
            if (selector.isReady(socket)) {
                receiveUpdates();
            }
        }
        sendInput();
    }

    socket.disconnect();
}

void Client::stop() {
    running = false;
}

void Client::sendInput() {
    sf::Packet packet;
    packet << PacketType::PLAYER_INPUT;


    if(World::player != nullptr)
        World::player->serialize(packet);

    if(socket.send(packet) != sf::Socket::Done){
        std::cout << "Error while sending packet!" << std::endl;
    }
}

void Client::receiveUpdates() {
    sf::Packet packet;
    if(socket.receive(packet) == sf::Socket::Done){
        PacketType type;
        packet >> type;

        switch(type){
            case PacketType::PLAYER_UPDATE:
                if(!World::players.empty()){
                    World::players[0].deserialize(packet);
                }
                std::cout << "Received player update from server!" << std::endl;
                break;
            default:
                break;
        }
    }
}