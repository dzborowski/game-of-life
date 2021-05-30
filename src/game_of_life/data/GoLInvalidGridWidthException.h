//
// Created by damian on 30.05.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GOLINVALIDGRIDWIDTHEXCEPTION_H
#define GAME_OF_LIFE_PW_DZ_GOLINVALIDGRIDWIDTHEXCEPTION_H

#include <exception>

class GoLInvalidGridWidthException : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "Invalid grid width was provided.";
    }
};


#endif //GAME_OF_LIFE_PW_DZ_GOLINVALIDGRIDWIDTHEXCEPTION_H
