//
// Created by damian on 08.04.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_CELL_H
#define GAME_OF_LIFE_PW_DZ_CELL_H


class Cell {
public:
    [[nodiscard]] bool isAlive() const;

    void setIsAlive(bool Alive) const;

    void display() const;

private:
    mutable bool _isAlive = false;
};


#endif //GAME_OF_LIFE_PW_DZ_CELL_H
