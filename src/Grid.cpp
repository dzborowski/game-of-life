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

int Grid::getWidth() const {
    return width;
}

int Grid::getHeight() const {
    return height;
}

std::shared_ptr<Cell> Grid::getCell(int cellX, int cellY) {
    return this->cells->at(cellY)->at(cellX);
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
