//
// Created by damian on 24.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_EDGENEIGHBORHOOD_H
#define GAME_OF_LIFE_PW_DZ_EDGENEIGHBORHOOD_H


#include "Neighborhood.h"

class EdgeNeighborhood : public Neighborhood {
public:
    explicit EdgeNeighborhood(const std::vector<std::shared_ptr<Cell>> &neighbors);
};


#endif //GAME_OF_LIFE_PW_DZ_EDGENEIGHBORHOOD_H
