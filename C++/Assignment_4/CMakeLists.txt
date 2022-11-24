cmake_minimum_required( VERSION 3.14 )

project( Assignment_4 )

add_executable( program src/main.cpp src/Function.cpp )

INCLUDE_DIRECTORIES ( include )

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
