#ifndef DUNGEONC_PLAYER_H
#define DUNGEONC_PLAYER_H

#include "entity/Entity.h"

namespace Direction {
    enum ID {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };
}

class Player : Entity {
public:
    Player();
    Player(Vector2 position, Vector2 direction, float velocity);
    ~Player() override;

    void move(Direction::ID direction);

    void update(float deltaTime) override;
    void render() override;
    sf::Texture getTexture() override;
    void setTexture(sf::Texture sprite) override;

    void setVelocity(float velocity);

    void setDirX(float x);
    void setDirY(float y);

    float getX() const;
    float getY() const;
};

#endif //DUNGEONC_PLAYER_H