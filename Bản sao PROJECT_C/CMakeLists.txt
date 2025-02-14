cmake_minimum_required(VERSION 3.15)
project(PROJECT_C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(PROJECT_C main.c src/function.c include/function.h)
