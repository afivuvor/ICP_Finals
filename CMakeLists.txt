cmake_minimum_required(VERSION 3.23)
project(ICPFinalCProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(ICPFinalCProject main.cpp Airports.cpp Airlines.h Airlines.h Airlines.cpp Routes.cpp Routes.h)
