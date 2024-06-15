//
// Created by leonv on 15.06.2024.
//

#ifndef DUNGEONC_PACKETTYPES_H
#define DUNGEONC_PACKETTYPES_H

enum PacketType {
    CONNECTION_REQUEST,
    CONNECTION_ACCEPTED,
    CONNECTION_DENIED,
    DISCONNECT,
    PLAYER_INPUT,
    PLAYER_UPDATE,
    ENEMY_UPDATE,
    ENEMY_SPAWN,
    ENEMY_DESPAWN,
    PLAYER_SPAWN,
    PLAYER_DESPAWN,
    GAME_OVER
};

inline sf::Packet& operator <<(sf::Packet& packet, const PacketType& type) {
    return packet << static_cast<sf::Uint8>(type);
}

inline sf::Packet& operator >>(sf::Packet& packet, PacketType& type) {
    sf::Uint8 value;
    packet >> value;
    type = static_cast<PacketType>(value);
    return packet;
}

#endif //DUNGEONC_PACKETTYPES_H
