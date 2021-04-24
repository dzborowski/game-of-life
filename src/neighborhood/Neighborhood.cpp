//
// Created by damian on 24.04.2021.
//

#include "Neighborhood.h"

#include <utility>

Neighborhood::Neighborhood(std::vector<std::shared_ptr<Cell>> neighbors) : neighbors(std::move(neighbors)) {}

int Neighborhood::getAliveCellsCount() {
    int count = 0;
    for (auto &cell : this->neighbors) {
        if (cell->isAlive())
            count++;
    }
    return count;
}
