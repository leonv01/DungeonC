//
// Created by leonv on 14.06.2024.
//

#ifndef DUNGEONC_ENEMY_H
#define DUNGEONC_ENEMY_H

#include "entity/Entity.h"

#include <SFML/Graphics.hpp>

class Enemy : private Entity {
public:
    Enemy();
    Enemy(Vector2 position, Vector2 direction, float velocity);
    ~Enemy() override;

    void update(float deltaTime) override;
    void render() override;
    sf::Texture getTexture() override;
};


#endif //DUNGEONC_ENEMY_H
