//
// Created by leonv on 14.06.2024.
//

#include "core/Game.h"

void Game::run() {
    World::generate();

    loadResources();

    Render::createWindow();

    while (Render::isOpen()) {
        update();
    }
}

void Game::loadResources() {
    loadTextures();
}

void Game::loadTextures() {
    textureManager.load(Texture::ID::PLAYER, R"(C:\Users\leonv\Documents\Projects\DungeonC\ressources\sprite\player.png)");
    textureManager.load(Texture::ID::ENEMY, R"(C:\Users\leonv\Documents\Projects\DungeonC\ressources\sprite\enemy.png)");

    for(auto& player : World::players) {
        player.setTexture(textureManager.get(Texture::ID::PLAYER));
    }
}

void Game::loadSounds(){

}

void Game::loadMusic(){

}

void Game::loadFonts(){

}

void Game::update() {
    for (auto event = sf::Event{}; Render::window->pollEvent(event);) {
        if (event.type == sf::Event::Closed) {
            Render::closeWindow();
        }
    }

    Render::clearWindow();

    for(auto& player : World::players) {
        sf::Texture texture = player.getTexture();
        sf::Sprite sprite(texture);
        sprite.setPosition(200, 200);
        sprite.setScale(10, 10);
        Render::window->draw(sprite);
    }

    Render::displayWindow();
}


