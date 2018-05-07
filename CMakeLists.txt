cmake_minimum_required(VERSION 3.1.3)
project(BactEvolution LANGUAGES CXX)
		
set(CMAKE_CXX_STANDARD 14) # Use C++14

add_executable(exe Bacteria.cpp Simulation.cpp Grid.cpp Ga.cpp Gb.cpp exe.cpp Cell.cpp Coordinates.cpp)
add_executable(testsElise Bacteria.cpp Simulation.cpp Grid.cpp Ga.cpp Gb.cpp testsElise.cpp Cell.cpp Coordinates.cpp)
add_executable(testsGuillaume Bacteria.cpp Simulation.cpp Grid.cpp Ga.cpp Gb.cpp testsGuillaume.cpp Cell.cpp Coordinates.cpp)
add_executable(testsHana Bacteria.cpp Simulation.cpp Grid.cpp Ga.cpp Gb.cpp testsHana.cpp Cell.cpp Coordinates.cpp)

