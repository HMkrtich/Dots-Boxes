cmake_minimum_required(VERSION 3.23)
project(Dots)

set(CMAKE_CXX_STANDARD 20)

add_executable(Dots main.cpp Board.h Line.h Box.h Line.cpp Box.cpp Board.cpp Game.h MySet.h)
