//
// Created by damian on 08.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GRID_H
#define GAME_OF_LIFE_PW_DZ_GRID_H

#include <iostream>
#include <vector>
#include <memory>
#include "Cell.h"

class Grid {

public:
    Grid(int width, int height);

    void display();

    int getAliveCellNeighborsCount(int cellX, int cellY);

    bool isCellAlive(int cellX, int cellY);

    void killCell(int cellX, int cellY);

    void reviveCell(int cellX, int cellY);

    void recalculateNewGridState(std::shared_ptr<Grid> oldGrid);

private:
    int width = 0;
    int height = 0;
    std::unique_ptr<std::vector<std::unique_ptr<std::vector<std::shared_ptr<Cell>>>>> cells;

    std::vector<std::shared_ptr<Cell>> getCellNeighbors(int cellX, int cellY);

    std::shared_ptr<Cell> getCell(int cellX, int cellY);
};


#endif //GAME_OF_LIFE_PW_DZ_GRID_H
