//
// Created by leonv on 14.06.2024.
//

#ifndef DUNGEONC_WORLD_H
#define DUNGEONC_WORLD_H

#include<memory>
#include <vector>

#include "entity/Entity.h"
#include "entity/Player.h"
#include "entity/Enemy.h"
#include "core/Serializable.h"

class World : Serializable{
public:
    inline static std::shared_ptr<Player> player;
    inline static std::vector<Entity> entities;
    inline static std::vector<Player> players;
    inline static std::vector<Enemy> enemies;

    void serialize(sf::Packet& packet) const override;
    void deserialize(sf::Packet& packet) override;

    static void generate();
    static void addPlayer(const Player& player);
};

#endif //DUNGEONC_WORLD_H
