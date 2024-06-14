//
// Created by leonv on 14.06.2024.
//

#ifndef DUNGEONC_RENDER_H
#define DUNGEONC_RENDER_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

struct Render{
    inline static std::unique_ptr<sf::RenderWindow> window;
    inline static int width = 800;
    inline static int height = 600;
    inline static std::string title = "DungeonC";
    inline static int framerate = 60;

    static void createWindow(){
        window = std::make_unique<sf::RenderWindow>(sf::VideoMode(width, height), title);
        window->setFramerateLimit(framerate);
    }

    static void clearWindow(){
        window->clear();
    }

    static void displayWindow(){
        window->display();
    }

    static void closeWindow(){
        window->close();
    }

    static bool isOpen(){
        return window->isOpen();
    }

};

#endif //DUNGEONC_RENDER_H
