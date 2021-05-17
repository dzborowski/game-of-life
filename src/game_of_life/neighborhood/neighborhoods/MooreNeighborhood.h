//
// Created by damian on 24.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_MOORENEIGHBORHOOD_H
#define GAME_OF_LIFE_PW_DZ_MOORENEIGHBORHOOD_H


#include "Neighborhood.h"

class MooreNeighborhood : public Neighborhood {
public:
    explicit MooreNeighborhood(const std::vector<std::shared_ptr<Cell>> &neighbors);
};


#endif //GAME_OF_LIFE_PW_DZ_MOORENEIGHBORHOOD_H
