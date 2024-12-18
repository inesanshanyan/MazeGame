#include "maze.hpp"

// Prime algorithm
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

    if (!isConnected(0, 0, width - 1, height - 1)) {
        connectStartAndEnd();
    }
}

const std::vector<std::vector<bool>>& Maze::getMaze() const {
    return maze;
}

void Maze::dfs(int startX, int startY, std::vector<std::vector<bool>>& visited) {
    std::stack<std::pair<int, int>> stack;
    stack.push({startX, startY});
    visited[startY][startX] = true;

    while (!stack.empty()) {
        auto [x, y] = stack.top();
        stack.pop();

        if (x > 0 && !visited[y][x - 1] && maze[y][x - 1]) {
            stack.push({x - 1, y});
            visited[y][x - 1] = true;
        }
        if (x < width - 1 && !visited[y][x + 1] && maze[y][x + 1]) {
            stack.push({x + 1, y});
            visited[y][x + 1] = true;
        }
        if (y > 0 && !visited[y - 1][x] && maze[y - 1][x]) {
            stack.push({x, y - 1});
            visited[y - 1][x] = true;
        }
        if (y < height - 1 && !visited[y + 1][x] && maze[y + 1][x]) {
            stack.push({x, y + 1});
            visited[y + 1][x] = true;
        }
    }
}

bool Maze::isConnected(int startX, int startY, int endX, int endY) {
    std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));
    dfs(startX, startY, visited);
    return visited[endY][endX];
}

void Maze::connectStartAndEnd() {
    int x = 0, y = 0;
    std::vector<std::pair<int, int>> moves = {{0, 1}, {1, 0}};

    while (x != width - 1 || y != height - 1) {
        std::random_shuffle(moves.begin(), moves.end());

        for (const auto& move : moves) {
            int newX = x + move.first;
            int newY = y + move.second;

            if (newX < width && newY < height) {
                x = newX;
                y = newY;
                maze[y][x] = true;
                break;
            }
        }
    }

    maze[height - 1][width - 1] = true;
}


int Maze::getMazeWidth() const{
    return width;
}


int Maze::getMazeHeight() const{
    return height;
}

