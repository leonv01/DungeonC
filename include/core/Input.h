//
// Created by leonv on 17.06.2024.
//

#ifndef DUNGEONC_INPUT_H
#define DUNGEONC_INPUT_H

#include <SFML/Window/Keyboard.hpp>
#include "core/World.h"
#include "core/Game.h"

class Input {
public:
    static void handleInput() {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            World::player->moveUp();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            World::player->moveDown();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            World::player->moveLeft();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            World::player->moveRight();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            Game::setRunning(false);
        }
    }
};

#endif //DUNGEONC_INPUT_H
