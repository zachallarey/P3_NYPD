cmake_minimum_required(VERSION 3.28)
project(p3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(data)
include_directories(src)

add_executable(p3
        src/Astar.cpp
        src/Astar.h
        src/Dijkstra.cpp
        src/Dijkstra.h
        src/GraphAdjList.cpp
        src/GraphAdjList.h
        src/GraphAdjMatrix.cpp
        src/GraphAdjMatrix.h
        src/main.cpp
        src/data_generator.cpp)
