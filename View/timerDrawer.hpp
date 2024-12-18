#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include "../Components/timer.hpp"

class TimerDrawer {
public:
    TimerDrawer(sf::RenderWindow &win, Timer &t);
    void draw();

private:
    sf::RenderWindow &window;
    Timer &timer;
    
    sf::Font font;
    sf::Text timerText;
};


