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

    sf::Font levelFont;
    sf::Text levelText;

    const int scale = 20;

    void drawBackground();
    void drawMazeBorder();
    void drawMaze();
    void drawFlag();
    void drawArrows();
    void drawPlayer();
    void drawLevel();
    
};
