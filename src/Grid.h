//
// Created by damian on 08.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GRID_H
#define GAME_OF_LIFE_PW_DZ_GRID_H

#include <iostream>
#include <vector>
#include <memory>
#include "Cell.h"

template<typename T>
class Grid {

public:
    Grid(int width, int height);

    void display() const;

    [[nodiscard]] constexpr int getWidth() const;

    [[nodiscard]] constexpr int getHeight() const;

    std::shared_ptr<T> getElement(int x, int y) const;

private:
    int width = 0;
    int height = 0;

    std::unique_ptr<std::vector<std::unique_ptr<std::vector<std::shared_ptr<T>>>>> elements;
};

template<typename T>
Grid<T>::Grid(int width, int height) : width(width), height(height) {
    this->elements = std::make_unique<std::vector<std::unique_ptr<std::vector<std::shared_ptr<T>>>>>();

    for (int i = 0; i < height; ++i) {
        auto row = std::make_unique<std::vector<std::shared_ptr<T>>>();
        for (int j = 0; j < width; ++j)
            row->push_back(std::make_shared<T>());
        this->elements->push_back(std::move(row));
    }
}

template<typename T>
constexpr int Grid<T>::getWidth() const {
    return width;
}

template<typename T>
constexpr int Grid<T>::getHeight() const {
    return height;
}

template<typename T>
std::shared_ptr<T> Grid<T>::getElement(int x, int y) const {
    return this->elements->at(y)->at(x);
}

template<typename T>
void Grid<T>::display() const {
    for (const auto &row : *this->elements) {
        for (const auto &element :*row) {
            element->display();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}


#endif //GAME_OF_LIFE_PW_DZ_GRID_H
