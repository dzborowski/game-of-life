//
// Created by damian on 08.04.2021.
//

#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <thread>
#include <ctime>
#include "GoLController.h"
#include "GoLService.h"
#include "GoLView.h"
#include "../lib/Simulator.h"

[[noreturn]] void GoLController::run() {
    constexpr int STEP_DELAY_MS = 1000;
    constexpr int INIT_GRID_WIDTH = 10;
    constexpr int INIT_GRID_HEIGHT = 5;

    auto gridSize = std::make_shared<GridSize>(INIT_GRID_WIDTH, INIT_GRID_HEIGHT);
    auto startingLivingCellsCoordinates = this->getStartingLivingCellsCoordinates();
    auto goLService = std::make_unique<GoLService>(std::move(startingLivingCellsCoordinates));
    auto goLView = std::make_unique<GoLView>();
    Simulator<GoLService, GoLView, Cell> simulator(std::move(goLService), std::move(goLView), gridSize);

    std::cout << "Initial game state" << std::endl << std::endl;
    simulator.display();
    std::cout << std::endl;

    while (true) {
        std::time_t startTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::cout << std::ctime(&startTime) << std::endl;

        simulator.makeStep();
        simulator.display();
        std::cout << std::endl;

        std::chrono::milliseconds delay(STEP_DELAY_MS);
        std::this_thread::sleep_for(delay);
    }
}


std::unique_ptr<std::vector<int>> GoLController::getStartingLivingCellsCoordinates() {
    auto coordinates = std::make_unique<std::vector<int>>();
    coordinates->insert(coordinates->end(), {1, 0, 2, 1, 0, 2, 1, 2, 2, 2});
    return coordinates;
}
