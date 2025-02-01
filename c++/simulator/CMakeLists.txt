cmake_minimum_required(VERSION 3.12)

# Set project name
project(SerialReader)
set(CMAKE_CXX_STANDARD 17)

# Add source files
file(GLOB SOURCES "src/*.cpp")

include_directories(include)



# Create the executable 
add_executable(${PROJECT_NAME} ${SOURCES})

# Lining necessary libraries 
target_link_libraries(${PROJECT_NAME} pthread)