//
// Created by damian on 24.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_NEIGHBORHOOD_H
#define GAME_OF_LIFE_PW_DZ_NEIGHBORHOOD_H

#include <iostream>
#include <vector>
#include <memory>
#include "../Cell.h"

class Neighborhood {
public:
    explicit Neighborhood(std::vector<std::shared_ptr<Cell>> neighbors);

    int getAliveCellsCount();

private:
    std::vector<std::shared_ptr<Cell>> neighbors;
};


#endif //GAME_OF_LIFE_PW_DZ_NEIGHBORHOOD_H
