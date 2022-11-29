cmake_minimum_required(VERSION 3.23)
project(ICP_FinalProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(ICP_FinalProject main.cpp cmake-build-debug/Routes.cpp cmake-build-debug/Routes.h cmake-build-debug/Airlines.h cmake-build-debug/Airlines.cpp cmake-build-debug/Airports.cpp cmake-build-debug/Airports.h cmake-build-debug/Main.cpp)

add_executable(Routes cmake-build-debug/Routes.cpp)

add_executable(Airlines cmake-build-debug/Airlines.h)
add_executable(Airports cmake-build-debug/Airports.h)

add_executable(Main cmake-build-debug/Main.cpp)
