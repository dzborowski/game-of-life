//
// Created by damian on 30.05.2021.
//

#include <iostream>
#include <string>
#include <exception>
#include "GoLDataProvider.h"
#include "../GoLConfig.h"
#include "GoLInvalidGridWidthException.h"
#include "GoLInvalidGridHeightException.h"
#include "GoLInvalidCellCoordinateYException.h"
#include "GoLInvalidCellCoordinateXException.h"
#include "GoLRepeatedCoordinatesException.h"

std::shared_ptr<GridSize> GoLDataProvider::getGridSize() noexcept {
    if (GoLConfig::IS_DEBUG) {
        return GoLDataProvider::getDefaultGridSize();
    }

    try {
        int gridWidth;
        std::cout << "Provide grid width, which must be positive integer: ";
        std::cin >> gridWidth;
        std::cout << std::endl;

        if (gridWidth <= 0) {
            throw GoLInvalidGridWidthException();
        }

        int gridHeight;
        std::cout << "Provide grid height, which must be positive integer: ";
        std::cin >> gridHeight;
        std::cout << std::endl;

        if (gridHeight <= 0) {
            throw GoLInvalidGridHeightException();
        }

        return std::make_shared<GridSize>(gridWidth, gridHeight);
    } catch (GoLInvalidGridWidthException &e) {
        std::cout << "Invalid grid width was provided." << std::endl;
        std::cout << "Default grid size will be used." << std::endl << std::endl;
        return GoLDataProvider::getDefaultGridSize();
    } catch (GoLInvalidGridHeightException &e) {
        std::cout << "Invalid grid height was provided." << std::endl;
        std::cout << "Default grid size will be used." << std::endl << std::endl;
        return GoLDataProvider::getDefaultGridSize();
    }
}

std::unique_ptr<std::vector<int>>
GoLDataProvider::getStartingLivingCellsCoordinates(std::shared_ptr<GridSize> gridSize) noexcept {
    if (GoLConfig::IS_DEBUG) {
        return GoLDataProvider::getDefaultStartingLivingCellsCoordinates();
    }

    int coordinatesCountLimit = gridSize->width * gridSize->height;
    auto coordinates = std::make_unique<std::vector<int>>();
    bool userWantsToAddMoreCoordinates = true;
    int tempCoordinateX;
    int tempCoordinateY;


    while (userWantsToAddMoreCoordinates) {
        if (coordinatesCountLimit == coordinates->size() / 2) {
            std::cout << "Cannot add more coordinates." << std::endl;
            break;
        }

        try {
            int coordinateX;
            std::cout << "Provide cell coordinate X, which must be natural integer in grid width range: ";
            std::cin >> coordinateX;
            std::cout << std::endl;

            if (coordinateX < 0 || coordinateX >= gridSize->width) {
                throw GoLInvalidCellCoordinateXException();
            }

            int coordinateY;
            std::cout << "Provide cell coordinate Y, which must be natural integer in grid height range: ";
            std::cin >> coordinateY;
            std::cout << std::endl;

            if (coordinateY < 0 || coordinateY >= gridSize->height) {
                throw GoLInvalidCellCoordinateYException();
            }
            if(std::equal_to<int>()(coordinateX,tempCoordinateX) && std::equal_to<int>()(coordinateY,tempCoordinateY)){
                throw GoLRepeatedCoordinatesException();

            }

            coordinates->push_back(coordinateX);
            coordinates->push_back(coordinateY);

            tempCoordinateX = coordinateX;
            tempCoordinateY = coordinateY;

            std::string response;
            std::cout << "Do you want add more coordinates[Yes/Other char]: ";
            std::cin >> response;
            std::cout << std::endl;


            if (std::not_equal_to<std::string>()(response,"Yes")) {
                userWantsToAddMoreCoordinates = false;
            }
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }

    }



    return std::move(coordinates);
}

std::shared_ptr<GridSize> GoLDataProvider::getDefaultGridSize() noexcept {
    return std::make_shared<GridSize>(GoLDataProvider::DEFAULT_GRID_WIDTH, GoLDataProvider::DEFAULT_GRID_HEIGHT);
}

std::unique_ptr<std::vector<int>> GoLDataProvider::getDefaultStartingLivingCellsCoordinates() noexcept {
    auto coordinates = std::make_unique<std::vector<int>>();
    coordinates->insert(coordinates->end(), {1, 0, 2, 1, 0, 2, 1, 2, 2, 2});
    return coordinates;
}
