//
// Created by damian on 24.04.2021.
//

#include <thread>
#include <atomic>
#include "Neighborhood.h"


Neighborhood::Neighborhood(std::vector<std::shared_ptr<Cell>> neighbors) : neighbors(std::move(neighbors)) {}


int Neighborhood::getAliveCellsCount() {
    std::atomic<int> count = 0;
    std::vector<std::thread> workers;

    for (auto &cell : this->neighbors) {
        workers.emplace_back([&count, &cell]() {
            if (cell->isAlive()) {
                count++;
            }
        });
    }

    for (auto &worker: workers) {
        worker.join();
    }

    return count;
}
