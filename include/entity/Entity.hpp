#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include "util/Vector2.hpp"

class Entity{
protected:
    Vector2 position;
    Vector2 direction;
    float velocity;
    
public:
    Entity() = default;
    virtual ~Entity() = default;

    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;
};

#endif // __ENTITY_HPP__