//
// Created by leonv on 14.06.2024.
//

#ifndef DUNGEONC_GAME_H
#define DUNGEONC_GAME_H

#include "SFML/Graphics/Texture.hpp"
#include "SFML/Audio/Sound.hpp"
#include "SFML/Audio/Music.hpp"
#include "SFML/Graphics/Font.hpp"

#include "core/ResourceManager.h"
#include "core/Resources.h"
#include "graphics/Render.h"
#include "core/World.h"

class Game {
public:
    static void run();
    static void update();

    static void loadResources();

    static void setRunning(bool _r) {
        Game::running = _r;
    }

    static bool isRunning() {
        return running;
    }

private:
    static void loadTextures();
    static void loadSounds();
    static void loadMusic();
    static void loadFonts();

    inline static ResourceManager<sf::Texture, Texture::ID> textureManager;
    inline static ResourceManager<sf::Sound, Sound::ID> soundManager;
    inline static ResourceManager<sf::Music, Music::ID> musicManager;
    inline static ResourceManager<sf::Font, Font::ID> fontManager;

    inline static bool running = true;

    inline static World world;
};


#endif //DUNGEONC_GAME_H
