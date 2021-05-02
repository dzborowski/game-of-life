//
// Created by damian on 24.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_NEIGHBORHOOD_H
#define GAME_OF_LIFE_PW_DZ_NEIGHBORHOOD_H

#include <iostream>
#include <vector>
#include <memory>
#include "../Cell.h"

template<typename T>
class Neighborhood {
public:
    explicit Neighborhood(std::vector<std::shared_ptr<T>> neighbors) : neighbors(std::move(neighbors)) {}

private:
public:
    const std::vector<std::shared_ptr<T>> &getNeighbors() const;

private:
    std::vector<std::shared_ptr<T>> neighbors;
};


template<typename T>
const std::vector<std::shared_ptr<T>> &Neighborhood<T>::getNeighbors() const {
    return neighbors;
}

#endif //GAME_OF_LIFE_PW_DZ_NEIGHBORHOOD_H
