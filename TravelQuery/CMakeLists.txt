cmake_minimum_required(VERSION 3.19)
project(TravelQuery C)

set(CMAKE_C_STANDARD 99)

add_executable(TravelQuery main.c SeqList.h AdjMGraph.h AdjMGraphCreate.h Dijkstra.h map.h)