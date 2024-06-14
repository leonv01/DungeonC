//
// Created by leonv on 14.06.2024.
//

#ifndef DUNGEONC_ANIMATOR_H
#define DUNGEONC_ANIMATOR_H

#include <SFML/Graphics.hpp>

class Animator {
public:

private:
    sf::Texture texture;

public:
    Animator();
    Animator(sf::Texture texture);

    void play();
    void pause();
    void stop();
    void update();

    void setTexture(sf::Texture texture);
    sf::Texture getTexture();

};


#endif //DUNGEONC_ANIMATOR_H
