cmake_minimum_required(VERSION 3.20)
project(FIFO_Buffer C)

set(CMAKE_C_STANDARD 99)

add_executable(FIFO_Buffer main.c fifo.c fifo.h)
