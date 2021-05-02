//
// Created by damian on 24.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_EDGENEIGHBORHOOD_H
#define GAME_OF_LIFE_PW_DZ_EDGENEIGHBORHOOD_H


#include "Neighborhood.h"

template<typename T>
class EdgeNeighborhood : public Neighborhood<T> {
public:
    explicit EdgeNeighborhood(const std::vector<std::shared_ptr<T>> &neighbors) : Neighborhood<T>(
            neighbors) {}
};


#endif //GAME_OF_LIFE_PW_DZ_EDGENEIGHBORHOOD_H
