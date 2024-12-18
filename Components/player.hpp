#pragma once

#include <vector>

#include "maze.hpp"

//class Maze;

class Player {
public:
    Player(int startX, int startY);
    
    void move(int dx, int dy, const Maze& maze);
    int getX() const;
    int getY() const;


private:
    int x;
    int y;
};
