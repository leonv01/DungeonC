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
    textureManager.load(Texture::ID::PLAYER, R"(C:\Users\leonv\Documents\Projects\DungeonC\resources\sprite\player.png)");
    textureManager.load(Texture::ID::ENEMY, R"(C:\Users\leonv\Documents\Projects\DungeonC\resources\sprite\enemy.png)");

    for(auto& player : World::players) {
        player.setTexture(textureManager.get(Texture::ID::PLAYER));
    }

    for(auto& enemy : World::enemies) {
        enemy.setTexture(textureManager.get(Texture::ID::ENEMY));
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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
        World::players[0].setDirY(-1);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        World::players[0].setDirY(1);
    }else{
        World::players[0].setDirY(0);
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        World::players[0].setDirX(-1);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        World::players[0].setDirX(1);
    }else{
        World::players[0].setDirX(0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
        World::players[0].setVelocity(10.0f);
    }else{
        World::players[0].setVelocity(5.0f);
    }

    for(auto& player : World::players) {

        player.update(1.0f);
        sf::Texture texture = player.getTexture();
        sf::Sprite sprite(texture);
        sprite.setPosition(player.getX(), player.getY());
        sprite.setScale(2.0f, 2.0f);
        Render::window->draw(sprite);
    }

    for(auto& enemy : World::enemies) {
        enemy.update(1.0f);
        sf::Texture texture = enemy.getTexture();
        sf::Sprite sprite(texture);
        sprite.setPosition(enemy.getX(), enemy.getY());
        sprite.setScale(2.0f, 2.0f);
        Render::window->draw(sprite);
    }


    Render::displayWindow();
}


