//
// Created by damian on 24.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_NEIGHBORHOODCALCULATOR_H
#define GAME_OF_LIFE_PW_DZ_NEIGHBORHOODCALCULATOR_H

#include <iostream>
#include <vector>
#include <memory>
#include "../Cell.h"
#include "Neighborhood.h"
#include "../Grid.h"

class NeighborhoodCalculator {
public:
    explicit NeighborhoodCalculator(std::shared_ptr<Grid> gird);

    template<typename T>
    auto getAliveCellNeighborsCount(T neighborhood) {
        return neighborhood.getAliveCellsCount();
    }

    Neighborhood getCellNeighborhood(int cellX, int cellY);

private:
    std::shared_ptr<Grid> gird;
};


#endif //GAME_OF_LIFE_PW_DZ_NEIGHBORHOODCALCULATOR_H
