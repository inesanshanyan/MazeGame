#include "maze.hpp"

Maze::Maze(int width, int height) : width(width), height(height) {
    maze.resize(height, std::vector<bool>(width, false));
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Maze::generateMaze() {
    int startX = std::rand() % width;
    int startY = std::rand() % height;
    maze[startY][startX] = true;

    std::vector<std::pair<int, int>> walls;

    if (startX > 0) walls.emplace_back(startX - 1, startY);
    if (startX < width - 1) walls.emplace_back(startX + 1, startY);
    if (startY > 0) walls.emplace_back(startX, startY - 1);
    if (startY < height - 1) walls.emplace_back(startX, startY + 1);

    while (!walls.empty()) {
        int randomIndex = std::rand() % walls.size();
        auto wall = walls[randomIndex];
        walls.erase(walls.begin() + randomIndex);

        int wx = wall.first;
        int wy = wall.second;

        int adjacentCells = 0;
        if (wx > 0 && maze[wy][wx - 1]) adjacentCells++;
        if (wx < width - 1 && maze[wy][wx + 1]) adjacentCells++;
        if (wy > 0 && maze[wy - 1][wx]) adjacentCells++;
        if (wy < height - 1 && maze[wy + 1][wx]) adjacentCells++;

        if (adjacentCells == 1) {
            maze[wy][wx] = true;

            if (wx > 0) walls.emplace_back(wx - 1, wy);
            if (wx < width - 1) walls.emplace_back(wx + 1, wy);
            if (wy > 0) walls.emplace_back(wx, wy - 1);
            if (wy < height - 1) walls.emplace_back(wx, wy + 1);
        }
    }

    maze[0][0] = true;
    maze[height - 1][width - 1] = true;
}

const std::vector<std::vector<bool>>& Maze::getMaze() const {
    return maze;
}
