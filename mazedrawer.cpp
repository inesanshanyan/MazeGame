#include "mazedrawer.hpp"

#include <QPainter>

MazeDrawer::MazeDrawer(Maze* maze, QWidget *parent)
    : QWidget(parent), maze(maze) {
    setFixedSize(maze->getMaze()[0].size() * 20, maze->getMaze().size() * 20); // cells
}

void MazeDrawer::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    const auto& mazeData = maze->getMaze();

    QColor wallColor(0, 0, 0);
    QColor pathColor(224, 224, 224);

    for (int y = 0; y < mazeData.size(); ++y) {
        for (int x = 0; x < mazeData[0].size(); ++x) {
            if (mazeData[y][x]) {
                painter.fillRect(x * 20, y * 20, 20, 20, pathColor); // paths
            } else {
                painter.fillRect(x * 20, y * 20, 20, 20, wallColor); // walls
            }
        }
    }
}
