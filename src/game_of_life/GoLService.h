//
// Created by damian on 11.05.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GOLSERVICE_H
#define GAME_OF_LIFE_PW_DZ_GOLSERVICE_H

#include <memory>
#include "../lib/Grid.h"

class GoLService {
public:
    explicit GoLService(std::unique_ptr<std::vector<int>> coordinates);

    GoLService(GoLService &&other) noexcept;

    void initGridState(const std::shared_ptr<Grid<Cell>>& grid);

    void recalculateNewGridState(const std::shared_ptr<Grid<Cell>>& currentGrid, const std::shared_ptr<Grid<Cell>>& candidateGrid);

protected:
    std::unique_ptr<std::vector<int>> coordinates;



};


#endif //GAME_OF_LIFE_PW_DZ_GOLSERVICE_H
