//
// Created by Pawel on 24.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GRIDSIZE_H
#define GAME_OF_LIFE_PW_DZ_GRIDSIZE_H

class GridSize{
public:

    int width;
    int height;

    GridSize(int width, int height);
    GridSize(GridSize&& other) noexcept;
    ~GridSize();


private:

};


#endif //GAME_OF_LIFE_PW_DZ_GRIDSIZE_H
