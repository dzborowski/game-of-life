//
// Created by damian on 30.05.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GOLINVALIDCELLCOORDINATEXEXCEPTION_H
#define GAME_OF_LIFE_PW_DZ_GOLINVALIDCELLCOORDINATEXEXCEPTION_H


#include <exception>

class GoLInvalidCellCoordinateXException : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "Invalid cell coordinate X was provided.";
    }
};


#endif //GAME_OF_LIFE_PW_DZ_GOLINVALIDCELLCOORDINATEXEXCEPTION_H
