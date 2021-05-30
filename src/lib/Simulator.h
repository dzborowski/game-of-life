//
// Created by damian on 11.05.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_SIMULATOR_H
#define GAME_OF_LIFE_PW_DZ_SIMULATOR_H


#include <functional>
#include "Grid.h"
#include "GridSize.h"

template<typename S, typename V, typename T>
class Simulator {
public:
    explicit Simulator(
            std::unique_ptr<S> service,
            std::unique_ptr<V> view,
            std::shared_ptr<GridSize> gridSize
    ) : service(std::move(service)), view(std::move(view)), gridSize(gridSize) {
        try {
            this->currentGrid = std::make_shared<Grid<T>>(gridSize);
            this->candidateGrid = std::make_shared<Grid<T>>(gridSize);
            this->service->initGridState(this->currentGrid);
        } catch (...) {
            std::cout << "Something was wrong with Simulator initialization" << std::endl;
            throw std::exception();
        }
    }

    void makeStep() {
        try {
            this->service->recalculateNewGridState(this->currentGrid, this->candidateGrid);
            this->currentGrid = std::move(this->candidateGrid);
            this->candidateGrid = std::make_shared<Grid<T>>(this->gridSize);
        } catch (...) {
            std::cout << "Something was wrong with while making step" << std::endl;
            throw std::exception();
        }
    }

    void display() {
        try {
            this->view->display(this->currentGrid);
        } catch (...) {
            std::cout << "Something was wrong while displaying" << std::endl;
            throw std::exception();
        }
    }

protected:
    std::unique_ptr<S> service;
    std::unique_ptr<V> view;
    std::shared_ptr<Grid<T>> currentGrid;
    std::shared_ptr<Grid<T>> candidateGrid;
    std::shared_ptr<GridSize> gridSize;
};


#endif //GAME_OF_LIFE_PW_DZ_SIMULATOR_H
