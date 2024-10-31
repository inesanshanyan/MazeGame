#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>

class Maze {
public:
    Maze(int width, int height);
    void generateMaze();
    const std::vector<std::vector<bool>>& getMaze() const;

private:
    int width;
    int height;
    std::vector<std::vector<bool>> maze; // false = wall, true = path
};

