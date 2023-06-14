cmake_minimum_required(VERSION 3.23)
project(GraphAnalysis)

set(CMAKE_CXX_STANDARD 20)

add_executable(GraphAnalysis main.cpp Graph.cpp Graph.cpp
        Algorithms.cpp Algorithms.h CSVWriter.cpp CSVWriter.h)
