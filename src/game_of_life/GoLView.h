//
// Created by damian on 11.05.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GOLVIEW_H
#define GAME_OF_LIFE_PW_DZ_GOLVIEW_H


#include <memory>
#include "Cell.h"
#include "../lib/Grid.h"
#include "../lib/GridSize.h"

class GoLView {
public:
    void display(const std::shared_ptr<Grid<Cell>>& grid);
};


#endif //GAME_OF_LIFE_PW_DZ_GOLVIEW_H
