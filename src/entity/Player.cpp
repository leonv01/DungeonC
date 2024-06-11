#include "entity/Player.hpp"

#include <iostream>

Player::Player(){
    position = Vector2{ 0.0f, 0.0f };
    direction = Vector2{ 0.0f, 0.0f };
    velocity = 0.0f;
}

Player::Player(Vector2 _position, Vector2 _direction, float _velocity){
    position = _position;
    direction = _direction;
    velocity = _velocity;
}

Player::~Player() = default;

void Player::update(float deltaTime){ 
    position += direction * velocity * deltaTime;
}

void Player::render(){
    
}