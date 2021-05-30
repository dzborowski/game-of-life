#include "game_of_life/GoLController.h"

int main() {
    try {
        std::cout << "Game of Life" << std::endl << std::endl;

        GoLController goLController;
        goLController.run();
    } catch (...) {
        return 1;
    }
}