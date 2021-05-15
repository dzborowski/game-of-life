//
// Created by damian on 08.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GAMECONTROLLER_H
#define GAME_OF_LIFE_PW_DZ_GAMECONTROLLER_H

#include <vector>
#include <memory>
#include "../lib/Grid.h"
#include "neighborhood/NeighborhoodCalculator.h"

class GameController {
public:
    [[noreturn]] void run();

private:
    std::unique_ptr<std::vector<int>> getStartingLivingCellsCoordinates();
};


#endif //GAME_OF_LIFE_PW_DZ_GAMECONTROLLER_H
