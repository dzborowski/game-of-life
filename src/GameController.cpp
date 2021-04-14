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

void GameController::run() {
    std::cout << "Game of Life" << std::endl << std::endl;

    auto gridWidth = std::move(getGridSize()[0]);
    auto gridHeight = std::move(getGridSize()[1]);

//    auto gridWidth = this->getGridWidth();
//    auto gridHeight = this->getGridHeight();
    auto startingLivingCellsCoordinates = this->getStartingLivingCellsCoordinates();
    auto oldGrid = std::make_shared<Grid>(gridWidth, gridHeight);
    auto newGrid = std::make_unique<Grid>(gridWidth, gridHeight);

    for (int i = 0; i < startingLivingCellsCoordinates->size(); i += 2)
        oldGrid->reviveCell(startingLivingCellsCoordinates->at(i), startingLivingCellsCoordinates->at(i + 1));

    std::cout << "Starting setup" << std::endl << std::endl;
    oldGrid->display();
    std::cout << std::endl;

    while (true) {
        std::time_t startTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::cout << std::ctime(&startTime) << std::endl;

        newGrid->recalculateNewGridState(oldGrid);
        newGrid->display();
        std::cout << std::endl;

        oldGrid = std::move(newGrid);
        // std::move proof that newGrid is now point to nullptr
        if(newGrid == nullptr)
            std::cout<<"NewGrind -> nullptr: "<<std::endl;
        else
            newGrid->display();

        newGrid = std::make_unique<Grid>(gridWidth, gridHeight);

        std::chrono::milliseconds delay(1000);
        std::this_thread::sleep_for(delay);
    }
}

//int GameController::getGridWidth() {
//    return 10;
//}
//
//int GameController::getGridHeight() {
//    return 5;
//}

std::vector<int> GameController::getGridSize(){
    std::vector<int> getGridSize;
    getGridSize.push_back(10);
    getGridSize.push_back(5);
    return getGridSize;
}

std::unique_ptr<std::vector<int>> GameController::getStartingLivingCellsCoordinates() {
    auto coordinates = std::make_unique<std::vector<int>>();
    coordinates->insert(coordinates->end(), {1, 0, 2, 1, 0, 2, 1, 2, 2, 2});
    return coordinates;
}
