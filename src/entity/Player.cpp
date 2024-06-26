#include "entity/Player.h"

#include <iostream>

Player::Player(){
    position = Vector2{ 0.0f, 0.0f };
    direction = Vector2{ 0.0f, 0.0f };
    velocity = 0.0f;
    texture = sf::Texture{};
}

Player::Player(Vector2 _position, Vector2 _direction, float _velocity){
    position = _position;
    direction = _direction;
    velocity = _velocity;
    texture = sf::Texture{};
}

Player::~Player() = default;

void Player::update(float deltaTime){ 
    position += direction * velocity * deltaTime;
}

void Player::render(){
    
}

sf::Texture Player::getTexture() {
    return texture;
}

void Player::setTexture(sf::Texture texture) {
    this->texture = texture;
}

void Player::move(Direction::ID direction) {
    switch (direction) {
        case Direction::UP:
            this->direction = Vector2{ 0.0f, -1.0f };
            break;
        case Direction::DOWN:
            this->direction = Vector2{ 0.0f, 1.0f };
            break;
        case Direction::LEFT:
            this->direction = Vector2{ -1.0f, 0.0f };
            break;
        case Direction::RIGHT:
            this->direction = Vector2{ 1.0f, 0.0f };
            break;
    }
}

float Player::getX() const {
    return position.x;
}

float Player::getY() const {
    return position.y;
}

void Player::setDirX(float x) {
    direction.x = x;
}

void Player::setDirY(float y) {
    direction.y = y;
}

void Player::setVelocity(float velocity) {
    this->velocity = velocity;
}
