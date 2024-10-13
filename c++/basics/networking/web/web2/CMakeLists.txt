cmake_minimum_required(VERSION 3.10)

# Project name
project(TCPControlServer)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Boost Asio package
find_package(Boost REQUIRED COMPONENTS system)

# Include directories
include_directories(${Boost_INCLUDE_DIRS})

# Define the executable
add_executable(server main.cpp)

# Link Boost and pthread libraries
target_link_libraries(server ${Boost_LIBRARIES} pthread)
