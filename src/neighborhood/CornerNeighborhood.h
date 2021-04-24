//
// Created by damian on 24.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_CORNERNEIGHBORHOOD_H
#define GAME_OF_LIFE_PW_DZ_CORNERNEIGHBORHOOD_H


#include "Neighborhood.h"

class CornerNeighborhood : public Neighborhood {
public:
    CornerNeighborhood(const std::vector<std::shared_ptr<Cell>> &neighbors);
};


#endif //GAME_OF_LIFE_PW_DZ_CORNERNEIGHBORHOOD_H
