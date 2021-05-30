//
// Created by damian on 11.05.2021.
//

#include "GoLView.h"

void GoLView::display(const std::shared_ptr<Grid<Cell>>& grid) {
    auto gridSize = grid->getGridSize();

    for (int i = 0; i < gridSize->height; ++i) {
        for (int j = 0; j < gridSize->width; ++j) {
            auto element = grid->getElement(j, i);
            element->display();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}



