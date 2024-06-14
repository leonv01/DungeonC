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
