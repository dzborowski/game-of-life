//
// Created by damian on 30.05.2021.
//

#ifndef GAME_OF_LIFE_PW_DZ_GOLINVALIDGRIDHEIGHTEXCEPTION_H
#define GAME_OF_LIFE_PW_DZ_GOLINVALIDGRIDHEIGHTEXCEPTION_H

#include <exception>

class GoLInvalidGridHeightException : public std::exception {
    [[nodiscard]] const char *what() const noexcept override {
        return "Invalid grid width was provided.";
    }
};


#endif //GAME_OF_LIFE_PW_DZ_GOLINVALIDGRIDHEIGHTEXCEPTION_H
