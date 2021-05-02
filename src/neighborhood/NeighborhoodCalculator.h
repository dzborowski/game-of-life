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
#include "CornerNeighborhood.h"
#include "EdgeNeighborhood.h"
#include "MooreNeighborhood.h"
#include "../Grid.h"

template<typename T>
class NeighborhoodCalculator {
public:
    explicit NeighborhoodCalculator(std::shared_ptr<Grid<T>> gird) : gird(std::move(gird)) {}

    Neighborhood<T> getNeighborhood(int x, int y);

private:
    std::shared_ptr<Grid<T>> gird;
};

template<typename T>
Neighborhood<T> NeighborhoodCalculator<T>::getNeighborhood(int x, int y) {
    bool isLeftEdge = x == 0;
    bool isRightEdge = x == this->gird->getWidth() - 1;
    bool isTopEdge = y == 0;
    bool isBottomEdge = y == this->gird->getHeight() - 1;
    bool isLeftTopEdge = isLeftEdge && isTopEdge;
    bool isLeftBottomEdge = isLeftEdge && isBottomEdge;
    bool isRightTopEdge = isRightEdge && isTopEdge;
    bool isRightBottomEdge = isRightEdge && isBottomEdge;

    if (isLeftTopEdge) {
        return CornerNeighborhood<T>({
                                             this->gird->getElement(x + 1, y),
                                             this->gird->getElement(x + 1, y + 1),
                                             this->gird->getElement(x, y + 1)
                                     });
    } else if (isLeftBottomEdge) {
        return CornerNeighborhood<T>({
                                             this->gird->getElement(x, y - 1),
                                             this->gird->getElement(x + 1, y - 1),
                                             this->gird->getElement(x + 1, y)
                                     });
    } else if (isRightTopEdge) {
        return CornerNeighborhood<T>({
                                             this->gird->getElement(x - 1, y),
                                             this->gird->getElement(x - 1, y + 1),
                                             this->gird->getElement(x, y + 1)
                                     });
    } else if (isRightBottomEdge) {
        return CornerNeighborhood<T>({
                                             this->gird->getElement(x - 1, y),
                                             this->gird->getElement(x - 1, y - 1),
                                             this->gird->getElement(x, y - 1)
                                     });
    } else if (isLeftEdge) {
        return EdgeNeighborhood<T>({
                                           this->gird->getElement(x, y - 1),
                                           this->gird->getElement(x + 1, y - 1),
                                           this->gird->getElement(x + 1, y),
                                           this->gird->getElement(x + 1, y + 1),
                                           this->gird->getElement(x, y + 1),
                                   });
    } else if (isRightEdge) {
        return EdgeNeighborhood<T>({
                                           this->gird->getElement(x, y - 1),
                                           this->gird->getElement(x - 1, y - 1),
                                           this->gird->getElement(x - 1, y),
                                           this->gird->getElement(x - 1, y + 1),
                                           this->gird->getElement(x, y + 1),
                                   });
    } else if (isTopEdge) {
        return EdgeNeighborhood<T>({
                                           this->gird->getElement(x - 1, y),
                                           this->gird->getElement(x - 1, y + 1),
                                           this->gird->getElement(x, y + 1),
                                           this->gird->getElement(x + 1, y + 1),
                                           this->gird->getElement(x + 1, y),
                                   });
    } else if (isBottomEdge) {
        return EdgeNeighborhood<T>({
                                           this->gird->getElement(x - 1, y),
                                           this->gird->getElement(x - 1, y - 1),
                                           this->gird->getElement(x, y - 1),
                                           this->gird->getElement(x + 1, y - 1),
                                           this->gird->getElement(x + 1, y),
                                   });
    } else {
        return MooreNeighborhood<T>({
                                            this->gird->getElement(x - 1, y - 1),
                                            this->gird->getElement(x, y - 1),
                                            this->gird->getElement(x + 1, y - 1),
                                            this->gird->getElement(x - 1, y),
                                            this->gird->getElement(x + 1, y),
                                            this->gird->getElement(x - 1, y + 1),
                                            this->gird->getElement(x, y + 1),
                                            this->gird->getElement(x + 1, y + 1),
                                    });
    }
}

#endif //GAME_OF_LIFE_PW_DZ_NEIGHBORHOODCALCULATOR_H
