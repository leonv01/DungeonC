#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "entity/Entity.hpp"

class Player : private Entity {
public:
    Player();
    Player(Vector2 position, Vector2 direction, float velocity);
    ~Player() override;

    void update(float deltaTime) override;
    void render() override;
};

#endif // __PLAYER_HPP__