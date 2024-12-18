#include "basicGameController.hpp"

BasicGameController::BasicGameController(sf::RenderWindow &win)
    : window(win), game(1), drawer(win, game) {

}

void BasicGameController::execute() {
    sf::Event event;
    while (window.isOpen() && !game.isGameOver() && event.key.code != sf::Keyboard::Escape) {
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
            if(game.getLevel() == 6) {
                game.setGameOver(true);
            } 
            else {
                game.setGameOver(false);
            }
        }

        window.clear();
        drawer.draw();  
        window.display();
    }
}
