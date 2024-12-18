#pragma once

#include "../Game/basicGame.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

class BasicGameDrawer {
public:
    BasicGameDrawer(sf::RenderWindow &win, const BasicGame &gameInstance);
    void draw();

private:
    sf::RenderWindow &window;
    const BasicGame &game;
    
    const int scale = 20;
};
