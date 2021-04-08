//
// Created by damian on 08.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GAMECONTROLLER_H
#define GAME_OF_LIFE_PW_DZ_GAMECONTROLLER_H

#include <vector>
#include <memory>
#include "Grid.h"

class GameController {
public:
    void run();

private:
    int getGridWidth();

    int getGridHeight();

    std::unique_ptr<std::vector<int>> getStartingLivingCellsCoordinates();
};


#endif //GAME_OF_LIFE_PW_DZ_GAMECONTROLLER_H
