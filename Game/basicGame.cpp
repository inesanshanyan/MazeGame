#include "basicGame.hpp"

BasicGame::BasicGame(int level = 1) 
    : level(level), gameOver(false), player(0, 0), maze(5 + level * 5, 10 + level * 4) {
        
    int width = 5 + level * 5;  
    int height = 10 + level * 4; 

    maze = Maze(width, height);  
    generateMaze();              
    player = Player(0, 0);       
}

void BasicGame::generateMaze() {
    maze.generateMaze();  
}

void BasicGame::movePlayer(int dx, int dy) {
    player.move(dx, dy, maze);

    if (player.getX() == maze.getMaze()[0].size() - 1 && player.getY() == maze.getMaze().size() - 1) {
        gameOver = true;
    }
}

bool BasicGame::isGameOver() const {
    return gameOver;
}

const Maze &BasicGame::getMaze() const {
    return maze;
}

const Player &BasicGame::getPlayer() const {
    return player;
}

void BasicGame::nextLevel() {
    ++level;  
    int width = 5 + level * 5; 
    int height = 10 + level * 4; 
    
    maze = Maze(width, height);  
    generateMaze();  

    player = Player(0, 0);  
}

void BasicGame::setGameOver(bool b) {
    gameOver = b;
}

int BasicGame::getLevel() const {
    return level;
}
