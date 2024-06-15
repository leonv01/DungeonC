#ifndef DUNGEONC_PLAYER_H
#define DUNGEONC_PLAYER_H

#include "entity/Entity.h"
#include "core/Serializable.h"

namespace Direction {
    enum ID {
        UP,
        DOWN,
        LEFT,
        RIGHT,
    };
}

class Player : Entity, Serializable{
public:
    Player();
    Player(Vector2 position, Vector2 direction, float velocity);
    ~Player() override;

    void move(Direction::ID direction);
    void update(float deltaTime) override;
    void render() override;

    void serialize(sf::Packet& packet) const override;
    void deserialize(sf::Packet& packet) override;


    void setTexture(sf::Texture sprite) override;
    void setVelocity(float velocity);
    void setDirX(float x);
    void setDirY(float y);

    sf::Texture getTexture() override;
    float getX() const;
    float getY() const;
};

#endif //DUNGEONC_PLAYER_H