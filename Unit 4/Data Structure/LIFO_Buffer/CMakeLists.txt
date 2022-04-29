cmake_minimum_required(VERSION 3.20)
project(LIFO_Buffer C)

set(CMAKE_C_STANDARD 99)

add_executable(LIFO_Buffer main.c lifo.c lifo.h)
