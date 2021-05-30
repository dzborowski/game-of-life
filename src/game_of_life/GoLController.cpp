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
#include "logic/GoLService.h"
#include "view/GoLView.h"
#include "../lib/Simulator.h"
#include "data/GoLDataProvider.h"
#include "GoLConfig.h"

[[noreturn]] void GoLController::run() {
    GoLDataProvider goLDataProvider;
    auto gridSize = goLDataProvider.getGridSize();
    auto startingLivingCellsCoordinates = goLDataProvider.getStartingLivingCellsCoordinates(gridSize);

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

        std::chrono::milliseconds delay(GoLConfig::STEP_DELAY_MS);
        std::this_thread::sleep_for(delay);
    }
}