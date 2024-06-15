//
// Created by leonv on 15.06.2024.
//

#ifndef DUNGEONC_SERIALIZABLE_H
#define DUNGEONC_SERIALIZABLE_H

#include <SFML/Network.hpp>

class Serializable {
public:
    virtual void serialize(sf::Packet& packet) const = 0;
    virtual void deserialize(sf::Packet& packet) = 0;
};


#endif //DUNGEONC_SERIALIZABLE_H
