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
#include "../../lib/Grid.h"

template<typename T>
class NeighborhoodCalculator {
public:
    explicit NeighborhoodCalculator(std::shared_ptr<Grid<T>> grid) : grid(grid) {}

    Neighborhood getNeighborhood(int x, int y) {
        auto gridSize = this->grid->getGridSize();
        bool isLeftEdge = x == 0;
        bool isRightEdge = x == gridSize->width - 1;
        bool isTopEdge = y == 0;
        bool isBottomEdge = y == gridSize->height - 1;
        bool isLeftTopEdge = isLeftEdge && isTopEdge;
        bool isLeftBottomEdge = isLeftEdge && isBottomEdge;
        bool isRightTopEdge = isRightEdge && isTopEdge;
        bool isRightBottomEdge = isRightEdge && isBottomEdge;

        if (isLeftTopEdge) {
            return CornerNeighborhood({
                                              this->grid->getElement(x + 1, y),
                                              this->grid->getElement(x + 1, y + 1),
                                              this->grid->getElement(x, y + 1)
                                      });
        } else if (isLeftBottomEdge) {
            return CornerNeighborhood({
                                              this->grid->getElement(x, y - 1),
                                              this->grid->getElement(x + 1, y - 1),
                                              this->grid->getElement(x + 1, y)
                                      });
        } else if (isRightTopEdge) {
            return CornerNeighborhood({
                                              this->grid->getElement(x - 1, y),
                                              this->grid->getElement(x - 1, y + 1),
                                              this->grid->getElement(x, y + 1)
                                      });
        } else if (isRightBottomEdge) {
            return CornerNeighborhood({
                                              this->grid->getElement(x - 1, y),
                                              this->grid->getElement(x - 1, y - 1),
                                              this->grid->getElement(x, y - 1)
                                      });
        } else if (isLeftEdge) {
            return EdgeNeighborhood({
                                            this->grid->getElement(x, y - 1),
                                            this->grid->getElement(x + 1, y - 1),
                                            this->grid->getElement(x + 1, y),
                                            this->grid->getElement(x + 1, y + 1),
                                            this->grid->getElement(x, y + 1),
                                    });
        } else if (isRightEdge) {
            return EdgeNeighborhood({
                                            this->grid->getElement(x, y - 1),
                                            this->grid->getElement(x - 1, y - 1),
                                            this->grid->getElement(x - 1, y),
                                            this->grid->getElement(x - 1, y + 1),
                                            this->grid->getElement(x, y + 1),
                                    });
        } else if (isTopEdge) {
            return EdgeNeighborhood({
                                            this->grid->getElement(x - 1, y),
                                            this->grid->getElement(x - 1, y + 1),
                                            this->grid->getElement(x, y + 1),
                                            this->grid->getElement(x + 1, y + 1),
                                            this->grid->getElement(x + 1, y),
                                    });
        } else if (isBottomEdge) {
            return EdgeNeighborhood({
                                            this->grid->getElement(x - 1, y),
                                            this->grid->getElement(x - 1, y - 1),
                                            this->grid->getElement(x, y - 1),
                                            this->grid->getElement(x + 1, y - 1),
                                            this->grid->getElement(x + 1, y),
                                    });
        } else {
            return MooreNeighborhood({
                                             this->grid->getElement(x - 1, y - 1),
                                             this->grid->getElement(x, y - 1),
                                             this->grid->getElement(x + 1, y - 1),
                                             this->grid->getElement(x - 1, y),
                                             this->grid->getElement(x + 1, y),
                                             this->grid->getElement(x - 1, y + 1),
                                             this->grid->getElement(x, y + 1),
                                             this->grid->getElement(x + 1, y + 1),
                                     });
        }
    }

private:
    std::shared_ptr<Grid<T>> grid;
};

#endif //GAME_OF_LIFE_PW_DZ_NEIGHBORHOODCALCULATOR_H
