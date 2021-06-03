//
// Created by Pawel on 03.06.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GOLREPEATEDCOORDINATESEXCEPTION_H
#define GAME_OF_LIFE_PW_DZ_GOLREPEATEDCOORDINATESEXCEPTION_H

#include <exception>

class GoLRepeatedCoordinatesException  : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "Repeated Coordinates, the coordinate pair must be unique ";
    }
};

#endif //GAME_OF_LIFE_PW_DZ_GOLREPEATEDCOORDINATESEXCEPTION_H
