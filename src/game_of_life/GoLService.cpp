//
// Created by damian on 11.05.2021.
//

#include "GoLService.h"
#include "neighborhood/NeighborhoodCalculator.h"

GoLService::GoLService(std::unique_ptr<std::vector<int>> coordinates) : coordinates(std::move(coordinates)) {}

GoLService::GoLService(GoLService &&other) noexcept {
    this->coordinates = std::move(other.coordinates);
}

void GoLService::initGridState(const std::shared_ptr<Grid<Cell>> &grid) {
    for (int i = 0; i < this->coordinates->size(); i += 2) {
        auto oldCell = grid->getElement(this->coordinates->at(i), this->coordinates->at(i + 1));
        oldCell->setIsAlive(true);
    }
}

void GoLService::recalculateNewGridState(
        const std::shared_ptr<Grid<Cell>> &currentGrid,
        const std::shared_ptr<Grid<Cell>> &candidateGrid
) {
    auto gridSize = candidateGrid->getGridSize();
    NeighborhoodCalculator neighborhoodCalculator(currentGrid);

    for (int i = 0; i < gridSize->height; ++i) {
        for (int j = 0; j < gridSize->width; ++j) {
            auto oldCell = currentGrid->getElement(j, i);
            auto isOldCellAlive = oldCell->isAlive();
            auto neighborhood = neighborhoodCalculator.getNeighborhood(j, i);
            auto aliveOldCellNeighborsCount = neighborhood.getAliveCellsCount();
            auto newCell = candidateGrid->getElement(j, i);

            if (!isOldCellAlive && aliveOldCellNeighborsCount == 3)
                newCell->setIsAlive(true);

            if (isOldCellAlive && (aliveOldCellNeighborsCount == 2 || aliveOldCellNeighborsCount == 3))
                newCell->setIsAlive(true);

            if (isOldCellAlive && (aliveOldCellNeighborsCount < 2 || aliveOldCellNeighborsCount > 3))
                newCell->setIsAlive(false);
        }
    }
}
