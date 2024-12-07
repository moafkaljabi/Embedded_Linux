cmake_minimum_required(VERSION 3.10)

# Project name and version
project(HttpServer VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
set(SOURCES
    main.cpp
    request.cpp
    response.cpp
)

# Add the executable target
add_executable(HttpServer ${SOURCES})

# Include directories (if you have any custom headers in `include/`)
target_include_directories(HttpServer PRIVATE include)

# Link additional libraries if needed (e.g., pthread for threading)
target_link_libraries(HttpServer pthread)
