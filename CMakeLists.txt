cmake_minimum_required(VERSION 3.17)
project(VirusSpl)

set(CMAKE_CXX_STANDARD 11)

add_executable(VirusSpl src/main.cpp src/Session.cpp src/Agent.cpp src/Virus.cpp src/Graph.cpp src/Tree.cpp src/MaxRankTree.cpp src/CycleTree.cpp src/RootTree.cpp src/ContactTracer.cpp)