#ifndef DUNGEONC_ENTITY_H
#define DUNGEONC_ENTITY_H

#include "util/Vector2.hpp"
#include <SFML/Graphics.hpp>

enum class EntityState{
    Idle,
    Walking,
    Running,
    Jumping,
    Attacking,
    Dying
};

class Entity{
protected:
    Vector2 position;
    Vector2 direction;
    float velocity{};
    sf::Texture texture;
    EntityState state;
    
public:
    Entity() = default;
    virtual ~Entity() = default;

    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;

    virtual sf::Texture getTexture() = 0;
    virtual void setTexture(sf::Texture sprite) = 0;

    virtual Vector2 getPosition() const{
        return position;
    }

};


#endif // DUNGEONC_ENTITY_H