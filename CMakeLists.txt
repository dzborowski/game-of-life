cmake_minimum_required(VERSION 3.13)
project(game-of-life-pw_dz)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/GameController.cpp src/GameController.h src/Cell.cpp src/Cell.h src/Grid.cpp src/Grid.h src/neighborhood/NeighborhoodCalculator.cpp src/neighborhood/NeighborhoodCalculator.h src/neighborhood/MooreNeighborhood.cpp src/neighborhood/MooreNeighborhood.h src/neighborhood/EdgeNeighborhood.cpp src/neighborhood/EdgeNeighborhood.h src/neighborhood/CornerNeighborhood.cpp src/neighborhood/CornerNeighborhood.h src/neighborhood/Neighborhood.cpp src/neighborhood/Neighborhood.h src/GridSize.cpp src/GridSize.h)

add_executable(game-of-life-pw_dz ${SOURCE_FILES})