//
// Created by damian on 08.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GRID_H
#define GAME_OF_LIFE_PW_DZ_GRID_H

#include <iostream>
#include <vector>
#include <memory>
#include "../game_of_life/logic/Cell.h"
#include "GridSize.h"

template<typename T>
class Grid {

public:
    explicit Grid(std::shared_ptr<GridSize> gridSize);

    [[nodiscard]] std::shared_ptr<GridSize> getGridSize() const;

    std::shared_ptr<T> getElement(int x, int y) const;

private:
    std::shared_ptr<GridSize> gridSize;
    std::unique_ptr<std::vector<std::unique_ptr<std::vector<std::shared_ptr<T>>>>> elements;
};


template<typename T>
Grid<T>::Grid(std::shared_ptr<GridSize> gridSize) {
    this->gridSize = gridSize;
    this->elements = std::make_unique<std::vector<std::unique_ptr<std::vector<std::shared_ptr<T>>>>>();

    for (int i = 0; i < this->gridSize->height; ++i) {
        auto row = std::make_unique<std::vector<std::shared_ptr<T>>>();
        for (int j = 0; j < this->gridSize->width; ++j)
            row->push_back(std::make_shared<T>());
        this->elements->push_back(std::move(row));
    }
}

template<typename T>
std::shared_ptr<GridSize> Grid<T>::getGridSize() const {
    return this->gridSize;
}

template<typename T>
std::shared_ptr<T> Grid<T>::getElement(int x, int y) const {
    return this->elements->at(y)->at(x);
}


#endif //GAME_OF_LIFE_PW_DZ_GRID_H
