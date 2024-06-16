//
// Created by leonv on 14.06.2024.
//

#include "core/World.h"

void World::generate() {
    World::player = std::make_shared<Player>(Vector2(0, 0), Vector2(0, 0), 0);
}

void World::addPlayer(const Player& p) {
    players.push_back(p);
}


void World::deserialize(sf::Packet &packet) {

}

void World::serialize(sf::Packet &packet) const {
    packet << players.size();
    for(auto& p : players){
        p.serialize(packet);
    }

}

