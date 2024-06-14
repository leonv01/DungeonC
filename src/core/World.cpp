//
// Created by leonv on 14.06.2024.
//

#include "core/World.h"

void World::generate() {
    players.emplace_back(Vector2(300, 300), Vector2(1, 0), 0.5f);
    for (int i = 0; i < 10; i++) {
        enemies.emplace_back(Vector2(100 * i, 100 * i), Vector2(1, 0), 0.5f);
    }
}

