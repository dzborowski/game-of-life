//
// Created by damian on 24.04.2021.
//

#include "NeighborhoodCalculator.h"
#include "CornerNeighborhood.h"
#include "EdgeNeighborhood.h"
#include "MooreNeighborhood.h"

NeighborhoodCalculator::NeighborhoodCalculator(std::shared_ptr<Grid> gird) : gird(std::move(gird)) {}

Neighborhood NeighborhoodCalculator::getCellNeighborhood(int cellX, int cellY) {
    bool isLeftEdge = cellX == 0;
    bool isRightEdge = cellX == this->gird->getWidth() - 1;
    bool isTopEdge = cellY == 0;
    bool isBottomEdge = cellY == this->gird->getHeight() - 1;
    bool isLeftTopEdge = isLeftEdge && isTopEdge;
    bool isLeftBottomEdge = isLeftEdge && isBottomEdge;
    bool isRightTopEdge = isRightEdge && isTopEdge;
    bool isRightBottomEdge = isRightEdge && isBottomEdge;

    if (isLeftTopEdge) {
        return CornerNeighborhood({
                                          this->gird->getCell(cellX + 1, cellY),
                                          this->gird->getCell(cellX + 1, cellY + 1),
                                          this->gird->getCell(cellX, cellY + 1)
                                  });
    } else if (isLeftBottomEdge) {
        return CornerNeighborhood({
                                          this->gird->getCell(cellX, cellY - 1),
                                          this->gird->getCell(cellX + 1, cellY - 1),
                                          this->gird->getCell(cellX + 1, cellY)
                                  });
    } else if (isRightTopEdge) {
        return CornerNeighborhood({
                                          this->gird->getCell(cellX - 1, cellY),
                                          this->gird->getCell(cellX - 1, cellY + 1),
                                          this->gird->getCell(cellX, cellY + 1)
                                  });
    } else if (isRightBottomEdge) {
        return CornerNeighborhood({
                                          this->gird->getCell(cellX - 1, cellY),
                                          this->gird->getCell(cellX - 1, cellY - 1),
                                          this->gird->getCell(cellX, cellY - 1)
                                  });
    } else if (isLeftEdge) {
        return EdgeNeighborhood({
                                        this->gird->getCell(cellX, cellY - 1),
                                        this->gird->getCell(cellX + 1, cellY - 1),
                                        this->gird->getCell(cellX + 1, cellY),
                                        this->gird->getCell(cellX + 1, cellY + 1),
                                        this->gird->getCell(cellX, cellY + 1),
                                });
    } else if (isRightEdge) {
        return EdgeNeighborhood({
                                        this->gird->getCell(cellX, cellY - 1),
                                        this->gird->getCell(cellX - 1, cellY - 1),
                                        this->gird->getCell(cellX - 1, cellY),
                                        this->gird->getCell(cellX - 1, cellY + 1),
                                        this->gird->getCell(cellX, cellY + 1),
                                });
    } else if (isTopEdge) {
        return EdgeNeighborhood({
                                        this->gird->getCell(cellX - 1, cellY),
                                        this->gird->getCell(cellX - 1, cellY + 1),
                                        this->gird->getCell(cellX, cellY + 1),
                                        this->gird->getCell(cellX + 1, cellY + 1),
                                        this->gird->getCell(cellX + 1, cellY),
                                });
    } else if (isBottomEdge) {
        return EdgeNeighborhood({
                                        this->gird->getCell(cellX - 1, cellY),
                                        this->gird->getCell(cellX - 1, cellY - 1),
                                        this->gird->getCell(cellX, cellY - 1),
                                        this->gird->getCell(cellX + 1, cellY - 1),
                                        this->gird->getCell(cellX + 1, cellY),
                                });
    } else {
        return MooreNeighborhood({
                                         this->gird->getCell(cellX - 1, cellY - 1),
                                         this->gird->getCell(cellX, cellY - 1),
                                         this->gird->getCell(cellX + 1, cellY - 1),
                                         this->gird->getCell(cellX - 1, cellY),
                                         this->gird->getCell(cellX + 1, cellY),
                                         this->gird->getCell(cellX - 1, cellY + 1),
                                         this->gird->getCell(cellX, cellY + 1),
                                         this->gird->getCell(cellX + 1, cellY + 1),
        });
    }
}
