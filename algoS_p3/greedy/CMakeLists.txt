cmake_minimum_required(VERSION 3.5)
project(greedy)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra")

set(SOURCE_FILES
    edges.txt
    Graph.cpp
    jobs.txt
    mst.cpp
    test.txt)

add_executable(greedy ${SOURCE_FILES})