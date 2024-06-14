//
// Created by leonv on 14.06.2024.
//

#ifndef DUNGEONC_WORLD_H
#define DUNGEONC_WORLD_H

#include <memory>
#include <vector>

#include "entity/Entity.h"
#include "entity/Player.h"
#include "entity/Enemy.h"

class World{
public:
    inline static std::vector<Entity> entities;
    inline static std::vector<Player> players;
    inline static std::vector<Enemy> enemies;

    static void generate();
};

#endif //DUNGEONC_WORLD_H
