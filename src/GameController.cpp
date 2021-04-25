//
// Created by damian on 08.04.2021.
//

#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <ctime>
#include "GameController.h"
#include "neighborhood/NeighborhoodCalculator.h"
#include "GridSize.h"

[[noreturn]] void GameController::run() {
    std::cout << "Game of Life" << std::endl << std::endl;


    GridSize initial(10,5);
    auto size = std::move(initial);

    int gridWidth = size.width;
    int gridHeight = size.height;

    auto startingLivingCellsCoordinates = this->getStartingLivingCellsCoordinates();
    auto oldGrid = std::make_shared<Grid>(gridWidth, gridHeight);
    auto newGrid = std::make_shared<Grid>(gridWidth, gridHeight);

    for (int i = 0; i < startingLivingCellsCoordinates->size(); i += 2) {
        auto oldCell = oldGrid->getCell(startingLivingCellsCoordinates->at(i),
                                        startingLivingCellsCoordinates->at(i + 1));
        oldCell->setIsAlive(true);
    }

    std::cout << "Starting setup" << std::endl << std::endl;
    oldGrid->display();
    std::cout << std::endl;

    while (true) {
        std::time_t startTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::cout << std::ctime(&startTime) << std::endl;

        this->recalculateNewGridState(oldGrid, newGrid);
        newGrid->display();
        std::cout << std::endl;

        newGrid = std::make_unique<Grid>(gridWidth, gridHeight);

        std::chrono::milliseconds delay(1000);
        std::this_thread::sleep_for(delay);
    }
}


std::unique_ptr<std::vector<int>> GameController::getStartingLivingCellsCoordinates() {
    auto coordinates = std::make_unique<std::vector<int>>();
    coordinates->insert(coordinates->end(), {1, 0, 2, 1, 0, 2, 1, 2, 2, 2});
    return coordinates;
}
