#include "timerGameController.hpp"

TimerGameController::TimerGameController(sf::RenderWindow &win)
    : BasicGameController(win), timerDrawer(win, timer) {
    timer.start(timer.getInitTime()); 
}

void TimerGameController::execute() {
    sf::Event event;
    while (window.isOpen() && !game.isGameOver() && !timer.isTimeUp() && event.key.code != sf::Keyboard::Escape) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    game.movePlayer(0, -1);
                } else if (event.key.code == sf::Keyboard::Down) {
                    game.movePlayer(0, 1);
                } else if (event.key.code == sf::Keyboard::Left) {
                    game.movePlayer(-1, 0);
                } else if (event.key.code == sf::Keyboard::Right) {
                    game.movePlayer(1, 0);
                }
            }
        }

        if (game.isGameOver()) {
            game.nextLevel();

            if (game.getLevel() == 6) {
                game.setGameOver(true);
            } else {
                game.setGameOver(false);
            }

            timer.start(timer.getInitTime() + 3 * game.getLevel());
        }

        window.clear();
        drawer.draw();
        timerDrawer.draw();
        window.display();
    }
}
