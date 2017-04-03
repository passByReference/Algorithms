cmake_minimum_required(VERSION 3.5)
project(clustering)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    clustering1.txt clustering.cpp UnionFind.h)

add_executable(clustering ${SOURCE_FILES})