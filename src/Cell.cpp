//
// Created by damian on 08.04.2021.
//

#include <iostream>
#include "Cell.h"

bool Cell::isAlive() const {
    return _isAlive;
}

void Cell::setIsAlive(bool isAlive) {
    Cell::_isAlive = isAlive;
}

void Cell::display() const {
    auto message = this->isAlive() ? "O" : "X";
    std::cout << message;
}
