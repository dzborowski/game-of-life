//
// Created by damian on 30.05.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GOLINVALIDCELLCOORDINATEYEXCEPTION_H
#define GAME_OF_LIFE_PW_DZ_GOLINVALIDCELLCOORDINATEYEXCEPTION_H


#include <exception>

class GoLInvalidCellCoordinateYException : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "Invalid cell coordinate Y was provided.";
    }
};


#endif //GAME_OF_LIFE_PW_DZ_GOLINVALIDCELLCOORDINATEYEXCEPTION_H
