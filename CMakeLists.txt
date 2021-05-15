cmake_minimum_required(VERSION 3.13)
project(game-of-life-pw_dz)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/game_of_life/GameController.cpp src/game_of_life/GameController.h src/game_of_life/Cell.cpp src/game_of_life/Cell.h src/lib/Grid.cpp src/lib/Grid.h src/game_of_life/neighborhood/NeighborhoodCalculator.cpp src/game_of_life/neighborhood/NeighborhoodCalculator.h src/game_of_life/neighborhood/MooreNeighborhood.cpp src/game_of_life/neighborhood/MooreNeighborhood.h src/game_of_life/neighborhood/EdgeNeighborhood.cpp src/game_of_life/neighborhood/EdgeNeighborhood.h src/game_of_life/neighborhood/CornerNeighborhood.cpp src/game_of_life/neighborhood/CornerNeighborhood.h src/game_of_life/neighborhood/Neighborhood.cpp src/game_of_life/neighborhood/Neighborhood.h src/lib/GridSize.cpp src/lib/GridSize.h src/lib/Simulator.cpp src/lib/Simulator.h src/game_of_life/GoLService.cpp src/game_of_life/GoLService.h src/game_of_life/GoLView.cpp src/game_of_life/GoLView.h)

add_executable(game-of-life-pw_dz ${SOURCE_FILES})