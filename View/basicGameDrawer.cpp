#include "basicGameDrawer.hpp"

BasicGameDrawer::BasicGameDrawer(sf::RenderWindow &win, const BasicGame &gameInstance)
    : window(win), game(gameInstance) {}


void BasicGameDrawer::draw() {

    const auto &mazeData = game.getMaze().getMaze();

    int mazeWidth = mazeData[0].size() * scale;  
    int mazeHeight = mazeData.size() * scale;   

    sf::Color background(97, 104, 82);
    window.clear(background);

    int offsetX = (window.getSize().x - mazeWidth) / 2;
    int offsetY = (window.getSize().y - mazeHeight) / 2;

    sf::Color wallColor(127, 48, 37); 
    sf::Color borderColor(38, 15, 24);

    sf::Color pathColor(204, 204, 204);  
    sf::Color playerColor(50, 90, 65); 


    sf::RectangleShape mazeBorder(sf::Vector2f(mazeWidth, mazeHeight));
    mazeBorder.setPosition(offsetX, offsetY);
    mazeBorder.setFillColor(sf::Color::Transparent);
    mazeBorder.setOutlineColor(borderColor);
    mazeBorder.setOutlineThickness(5); 
    window.draw(mazeBorder);


    for (int y = 0; y < mazeData.size(); ++y) {
        for (int x = 0; x < mazeData[y].size(); ++x) {
            sf::RectangleShape cell(sf::Vector2f(scale, scale));
            cell.setPosition(offsetX + x * scale, offsetY + y * scale);

            if (mazeData[y][x]) {
                cell.setFillColor(pathColor);       
                cell.setOutlineThickness(0);  
            } else {
                cell.setFillColor(wallColor); 
                cell.setOutlineColor(borderColor);
                cell.setOutlineThickness(-1); 
            }

            window.draw(cell);
        }
    }


    sf::Texture flagTexture;
    if (!flagTexture.loadFromFile("Assets/flag.png")) {
        std::cerr << "Failed to load flag\n";
    } else {
        sf::Sprite flag(flagTexture);
        flag.setScale(0.09f, 0.09f); 
        flag.setPosition(offsetX + (mazeData[0].size() - 1) * scale, offsetY + (mazeData.size() - 1) * scale);
        window.draw(flag);
    }

    sf::Texture arrowTexture;
    if (!arrowTexture.loadFromFile("Assets/arrow.png")) {
        std::cerr << "Failed to load arrow\n";
    } else {
        sf::Sprite arrow(arrowTexture);
        arrow.setScale(0.09f, 0.09); 
        arrow.setPosition(offsetX + (mazeData[0].size() - 1) * scale + 30, offsetY + (mazeData.size() - 1) * scale);
        window.draw(arrow); 
        arrow.setPosition(offsetX - 45, offsetY);
        window.draw(arrow);
    }


    const Player &player = game.getPlayer();
    sf::CircleShape playerShape(10);
    playerShape.setFillColor(playerColor);
    playerShape.setPosition(offsetX + player.getX() * scale, offsetY + player.getY() * scale);
    window.draw(playerShape);
}

