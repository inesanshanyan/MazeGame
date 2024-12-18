#include "timerDrawer.hpp"
#include <sstream>

TimerDrawer::TimerDrawer(sf::RenderWindow &win, Timer &t) : window(win), timer(t) {
    if (!font.loadFromFile("Assets/baskerville-old-face.ttf")) {
        std::cerr << "Failed to load font!\n";
    }

    timerText.setFont(font);
    timerText.setCharacterSize(30);
    timerText.setFillColor(sf::Color::White);
    timerText.setPosition(10, 10);  
}

void TimerDrawer::draw() {
    std::stringstream timeStream;
    int seconds = static_cast<int>(timer.getRemainingTime());
    int minutes = seconds / 60;
    seconds = seconds % 60;

    timeStream << minutes << ":" << (seconds < 10 ? "0" : "") << seconds;

    timerText.setString(timeStream.str());

    window.draw(timerText); 
}



