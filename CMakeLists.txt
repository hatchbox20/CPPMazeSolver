cmake_minimum_required(VERSION 3.17)
project(Assignment_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Assignment_2
        src/main.cpp src/Maze.cpp src/Maze.h src/MazeStack.cpp src/MazeStack.h src/Node.cpp src/Node.h src/MazePosition.cpp src/MazePosition.h)
