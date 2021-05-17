cmake_minimum_required(VERSION 3.13)
project(game-of-life-pw_dz)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/game_of_life/GoLController.cpp src/game_of_life/GoLController.h src/game_of_life/Cell.cpp src/game_of_life/Cell.h src/lib/Grid.cpp src/lib/Grid.h src/game_of_life/neighborhood/GoLNeighborhoodCalculator.cpp src/game_of_life/neighborhood/GoLNeighborhoodCalculator.h src/game_of_life/neighborhood/neighborhoods/MooreNeighborhood.cpp src/game_of_life/neighborhood/neighborhoods/MooreNeighborhood.h src/game_of_life/neighborhood/neighborhoods/EdgeNeighborhood.cpp src/game_of_life/neighborhood/neighborhoods/EdgeNeighborhood.h src/game_of_life/neighborhood/neighborhoods/CornerNeighborhood.cpp src/game_of_life/neighborhood/neighborhoods/CornerNeighborhood.h src/game_of_life/neighborhood/neighborhoods/Neighborhood.cpp src/game_of_life/neighborhood/neighborhoods/Neighborhood.h src/lib/GridSize.cpp src/lib/GridSize.h src/lib/Simulator.cpp src/lib/Simulator.h src/game_of_life/GoLService.cpp src/game_of_life/GoLService.h src/game_of_life/GoLView.cpp src/game_of_life/GoLView.h)

add_executable(game-of-life-pw_dz ${SOURCE_FILES})