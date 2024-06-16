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

    World::player->setTexture(textureManager.get(Texture::ID::PLAYER));
    /*
    for(auto& player : World::players) {
        player.setTexture(textureManager.get(Texture::ID::PLAYER));
    }
     */

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
        World::player->setDirY(-1);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
        World::player->setDirY(1);
    }else{
        World::player->setDirY(0);
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        World::player->setDirX(-1);
    }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
        World::player->setDirX(1);
    }else{
        World::player->setDirX(0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
        World::player->setVelocity(10.0f);
    }else{
        World::player->setVelocity(5.0f);
    }

    //for(auto& player : World::players) {

    World::player->update(1.0f);
    sf::Texture texture = World::player->getTexture();
    sf::Sprite sprite(texture);
    sprite.setPosition(World::player->getX(), World::player->getY());
        sprite.setScale(2.0f, 2.0f);
        Render::window->draw(sprite);
    //}

    for(auto& p : World::players){
        p.update(1.0f);
        texture = p.getTexture();
        sprite = sf::Sprite(textureManager.get(Texture::ID::ENEMY));
        sprite.setPosition(p.getX(), p.getY());
        sprite.setScale(2.0f, 2.0f);
        Render::window->draw(sprite);
    }
/*
    for(auto& enemy : World::enemies) {
        enemy.update(1.0f);
        sf::Texture texture = enemy.getTexture();
        sf::Sprite sprite(texture);
        sprite.setPosition(enemy.getX(), enemy.getY());
        sprite.setScale(2.0f, 2.0f);
        Render::window->draw(sprite);
    }
*/

    Render::displayWindow();
}


