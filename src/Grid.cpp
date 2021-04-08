//
// Created by damian on 08.04.2021.
//

#include "Grid.h"

Grid::Grid(int width, int height) : width(width), height(height) {
    this->cells = std::make_unique<std::vector<std::unique_ptr<std::vector<std::shared_ptr<Cell>>>>>();

    for (int i = 0; i < height; ++i) {
        auto row = std::make_unique<std::vector<std::shared_ptr<Cell>>>();
        for (int j = 0; j < width; ++j)
            row->push_back(std::make_shared<Cell>());
        this->cells->push_back(std::move(row));
    }
}

void Grid::display() {
    for (auto &row : *this->cells) {
        for (auto &cell :*row) {
            cell->display();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::recalculateNewGridState(std::shared_ptr<Grid> oldGrid) {
    for (int i = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j) {
            auto aliveOldCellNeighborsCount = oldGrid->getAliveCellNeighborsCount(j, i);
            auto isOldCellAlive = oldGrid->isCellAlive(j, i);

            if (!isOldCellAlive && aliveOldCellNeighborsCount == 3)
                this->reviveCell(j, i);

            if (isOldCellAlive && (aliveOldCellNeighborsCount == 2 || aliveOldCellNeighborsCount == 3))
                this->reviveCell(j, i);

            if (isOldCellAlive && (aliveOldCellNeighborsCount < 2 || aliveOldCellNeighborsCount > 3))
                this->killCell(j, i);
        }
    }
}


int Grid::getAliveCellNeighborsCount(int cellX, int cellY) {
    int count = 0;
    for (auto &cell : this->getCellNeighbors(cellX, cellY)) {
        if (cell->isAlive())
            count++;
    }
    return count;
}

std::vector<std::shared_ptr<Cell>> Grid::getCellNeighbors(int cellX, int cellY) {
    std::vector<std::shared_ptr<Cell>> neighbors = {};

    bool isLeftEdge = cellX == 0;
    bool isRightEdge = cellX == this->width - 1;
    bool isTopEdge = cellY == 0;
    bool isBottomEdge = cellY == this->height - 1;
    bool isLeftTopEdge = isLeftEdge && isTopEdge;
    bool isLeftBottomEdge = isLeftEdge && isBottomEdge;
    bool isRightTopEdge = isRightEdge && isTopEdge;
    bool isRightBottomEdge = isRightEdge && isBottomEdge;

    if (isLeftTopEdge) {
        neighbors.push_back(this->getCell(cellX + 1, cellY));
        neighbors.push_back(this->getCell(cellX + 1, cellY + 1));
        neighbors.push_back(this->getCell(cellX, cellY + 1));
    } else if (isLeftBottomEdge) {
        neighbors.push_back(this->getCell(cellX, cellY - 1));
        neighbors.push_back(this->getCell(cellX + 1, cellY - 1));
        neighbors.push_back(this->getCell(cellX + 1, cellY));
    } else if (isRightTopEdge) {
        neighbors.push_back(this->getCell(cellX - 1, cellY));
        neighbors.push_back(this->getCell(cellX - 1, cellY + 1));
        neighbors.push_back(this->getCell(cellX, cellY + 1));
    } else if (isRightBottomEdge) {
        neighbors.push_back(this->getCell(cellX - 1, cellY));
        neighbors.push_back(this->getCell(cellX - 1, cellY - 1));
        neighbors.push_back(this->getCell(cellX, cellY - 1));
    } else if (isLeftEdge) {
        neighbors.push_back(this->getCell(cellX, cellY - 1));
        neighbors.push_back(this->getCell(cellX + 1, cellY - 1));
        neighbors.push_back(this->getCell(cellX + 1, cellY));
        neighbors.push_back(this->getCell(cellX + 1, cellY + 1));
        neighbors.push_back(this->getCell(cellX, cellY + 1));
    } else if (isRightEdge) {
        neighbors.push_back(this->getCell(cellX, cellY - 1));
        neighbors.push_back(this->getCell(cellX - 1, cellY - 1));
        neighbors.push_back(this->getCell(cellX - 1, cellY));
        neighbors.push_back(this->getCell(cellX - 1, cellY + 1));
        neighbors.push_back(this->getCell(cellX, cellY + 1));
    } else if (isTopEdge) {
        neighbors.push_back(this->getCell(cellX - 1, cellY));
        neighbors.push_back(this->getCell(cellX - 1, cellY + 1));
        neighbors.push_back(this->getCell(cellX, cellY + 1));
        neighbors.push_back(this->getCell(cellX + 1, cellY + 1));
        neighbors.push_back(this->getCell(cellX + 1, cellY));
    } else if (isBottomEdge) {
        neighbors.push_back(this->getCell(cellX - 1, cellY));
        neighbors.push_back(this->getCell(cellX - 1, cellY - 1));
        neighbors.push_back(this->getCell(cellX, cellY - 1));
        neighbors.push_back(this->getCell(cellX + 1, cellY - 1));
        neighbors.push_back(this->getCell(cellX + 1, cellY));
    } else {
        neighbors.push_back(this->getCell(cellX - 1, cellY - 1));
        neighbors.push_back(this->getCell(cellX, cellY - 1));
        neighbors.push_back(this->getCell(cellX + 1, cellY - 1));
        neighbors.push_back(this->getCell(cellX - 1, cellY));
        neighbors.push_back(this->getCell(cellX + 1, cellY));
        neighbors.push_back(this->getCell(cellX - 1, cellY + 1));
        neighbors.push_back(this->getCell(cellX, cellY + 1));
        neighbors.push_back(this->getCell(cellX + 1, cellY + 1));
    }

    return neighbors;
}

bool Grid::isCellAlive(int cellX, int cellY) {
    return this->getCell(cellX, cellY)->isAlive();
}

void Grid::killCell(int cellX, int cellY) {
    this->getCell(cellX, cellY)->setIsAlive(false);
}

void Grid::reviveCell(int cellX, int cellY) {
    this->getCell(cellX, cellY)->setIsAlive(true);
}

std::shared_ptr<Cell> Grid::getCell(int cellX, int cellY) {
    return this->cells->at(cellY)->at(cellX);
}
