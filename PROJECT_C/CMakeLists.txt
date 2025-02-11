cmake_minimum_required(VERSION 3.30)
project(PROJECT_C C)

set(CMAKE_C_STANDARD 11)

add_executable(PROJECT_C main.c
        cmake-build-debug/include/function.h
        cmake-build-debug/include/datatype.h
        src/function.c
        include/function.h
        include/datatype.h
)
