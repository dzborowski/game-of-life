//
// Created by damian on 08.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GAMECONTROLLER_H
#define GAME_OF_LIFE_PW_DZ_GAMECONTROLLER_H

#include <vector>
#include <memory>
#include "Grid.h"
#include "neighborhood/NeighborhoodCalculator.h"

class GameController {
public:
    [[noreturn]] void run();

private:

    std::unique_ptr<std::vector<int>> getStartingLivingCellsCoordinates();

    template<typename T>
    void recalculateNewGridState(const T &oldGrid, const T &newGrid) {
        auto height = newGrid->getHeight();
        auto width = newGrid->getWidth();
        NeighborhoodCalculator neighborhoodCalculator(oldGrid);

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                auto oldCell = oldGrid->getCell(j, i);
                auto isOldCellAlive = oldCell->isAlive();
                auto neighborhood = neighborhoodCalculator.getCellNeighborhood(j, i);
                auto aliveOldCellNeighborsCount = neighborhoodCalculator.getAliveCellNeighborsCount(neighborhood);
                auto newCell = newGrid->getCell(j, i);

                if (!isOldCellAlive && aliveOldCellNeighborsCount == 3)
                    newCell->setIsAlive(true);

                if (isOldCellAlive && (aliveOldCellNeighborsCount == 2 || aliveOldCellNeighborsCount == 3))
                    newCell->setIsAlive(true);

                if (isOldCellAlive && (aliveOldCellNeighborsCount < 2 || aliveOldCellNeighborsCount > 3))
                    newCell->setIsAlive(false);
            }
        }
    }
};


#endif //GAME_OF_LIFE_PW_DZ_GAMECONTROLLER_H
