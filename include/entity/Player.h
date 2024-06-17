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

static int id = 0;

class Player : Entity, Serializable{
private:
    int pid;
public:
    Player();
    Player(Vector2 position, Vector2 direction, float velocity);
    ~Player() override;

    void move(Direction::ID direction);
    void update(float deltaTime) override;
    void render() override;

    void serialize(sf::Packet& packet) const override;
    void deserialize(sf::Packet& packet) override;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void setTexture(sf::Texture sprite) override;
    void setVelocity(float velocity);
    void setDirX(float x);
    void setDirY(float y);

    sf::Texture getTexture() override;
    float getX() const;
    float getY() const;

    int getID();
};

#endif //DUNGEONC_PLAYER_H