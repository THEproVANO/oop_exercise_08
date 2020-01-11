cmake_minimum_required(VERSION 3.10.2)
project(oop_exercise_08)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(oop_exercise_08 main.cpp five_angles.cpp eight_angles.cpp six_angles.cpp factory.h factory.cpp subscriber.h processor.cpp processor.h subscriber.cpp)

