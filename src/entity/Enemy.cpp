//
// Created by leonv on 14.06.2024.
//

#include "entity/Enemy.h"

Enemy::Enemy() : Entity() {
    this->position = Vector2(0, 0);
    this->direction = Vector2(0, 0);
    this->velocity = 0;
}

Enemy::Enemy(Vector2 position, Vector2 direction, float velocity) {
    this->position = position;
    this->direction = direction;
    this->velocity = velocity;
}

Enemy::~Enemy() = default;

void Enemy::update(float deltaTime) {

}

void Enemy::render() {

}

sf::Texture Enemy::getTexture() {
    return sf::Texture();
}
