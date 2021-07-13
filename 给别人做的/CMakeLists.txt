cmake_minimum_required(VERSION 3.19)
project(lys C)

set(CMAKE_C_STANDARD 99)

add_executable(lys main.c LinList.h CollectionProcessing.h)