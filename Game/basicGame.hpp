#pragma once

#include "../Components/maze.hpp"
#include "../Components/player.hpp"

class BasicGame {
public:
    BasicGame(int level);

    void generateMaze();
    void movePlayer(int dx, int dy);
    bool isGameOver() const;
    const Maze &getMaze() const;
    const Player &getPlayer() const;
    void nextLevel();  // Method to go to the next level

    void setGameOver(bool b);
    int getLevel() const;
    

private:
    Maze maze;
    Player player;
    bool gameOver;
    int level;
};
