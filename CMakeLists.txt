cmake_minimum_required(VERSION 3.13)
project(game-of-life-pw_dz)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES src/main.cpp src/GameController.cpp src/GameController.h src/Cell.cpp src/Cell.h src/Grid.cpp src/Grid.h)

add_executable(game-of-life-pw_dz ${SOURCE_FILES})