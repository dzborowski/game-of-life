//
// Created by damian on 08.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GOLCONTROLLER_H
#define GAME_OF_LIFE_PW_DZ_GOLCONTROLLER_H

#include <vector>
#include <memory>
#include "../lib/Grid.h"
#include "neighborhood/GoLNeighborhoodCalculator.h"

class GoLController {
public:
    [[noreturn]] void run();

private:
    std::unique_ptr<std::vector<int>> getStartingLivingCellsCoordinates();
};


#endif //GAME_OF_LIFE_PW_DZ_GOLCONTROLLER_H