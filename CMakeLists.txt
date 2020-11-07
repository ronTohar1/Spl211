cmake_minimum_required(VERSION 3.17)
project(VirusSpl)

set(CMAKE_CXX_STANDARD 11)

add_executable(VirusSpl main.cpp Session.cpp Agent.cpp Virus.cpp Graph.cpp)