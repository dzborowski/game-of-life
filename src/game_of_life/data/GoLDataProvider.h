//
// Created by damian on 30.05.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GOLDATAPROVIDER_H
#define GAME_OF_LIFE_PW_DZ_GOLDATAPROVIDER_H


#include <memory>
#include <vector>
#include "../../lib/GridSize.h"

class GoLDataProvider {
public:
    std::shared_ptr<GridSize> getGridSize() noexcept;
    std::unique_ptr<std::vector<int>> getStartingLivingCellsCoordinates(std::shared_ptr<GridSize> gridSize) noexcept;

protected:
    constexpr static int DEFAULT_GRID_WIDTH = 10;
    constexpr static int DEFAULT_GRID_HEIGHT = 5;

    static std::shared_ptr<GridSize> getDefaultGridSize() noexcept;
    static std::unique_ptr<std::vector<int>> getDefaultStartingLivingCellsCoordinates() noexcept;
};


#endif //GAME_OF_LIFE_PW_DZ_GOLDATAPROVIDER_H
