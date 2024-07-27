cmake_minimum_required(VERSION 3.10)
project(EmployeeManagement)

find_package(MySQLConnectorCpp REQUIRED)

include_directories(${MySQLConnectorCpp_INCLUDE_DIRS})

add_executable(my_program main.cpp)

target_link_libraries(my_program ${MySQLConnectorCpp_LIBRARIES})
