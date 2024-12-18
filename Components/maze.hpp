#pragma once

#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <algorithm>  

class Maze {
public:
    Maze(int width, int height);
    void generateMaze();
    const std::vector<std::vector<bool>>& getMaze() const;

    int getMazeWidth() const;
    int getMazeHeight() const;

private:
    bool isConnected(int startX, int startY, int endX, int endY);
    void connectStartAndEnd();
    void dfs(int startX, int startY, std::vector<std::vector<bool>>& visited);

    int width;
    int height;
    std::vector<std::vector<bool>> maze;
};
