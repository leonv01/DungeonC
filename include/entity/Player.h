#ifndef DUNGEONC_PLAYER_H
#define DUNGEONC_PLAYER_H

#include "entity/Entity.h"

class Player : private Entity {
public:
    Player();
    Player(Vector2 position, Vector2 direction, float velocity);
    ~Player() override;

    void update(float deltaTime) override;
    void render() override;
    sf::Texture getTexture() override;
    void setTexture(sf::Texture sprite) override;
};

#endif //DUNGEONC_PLAYER_H