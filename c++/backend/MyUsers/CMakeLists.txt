cmake_minimum_required(VERSION 3.16)

project(MyUsers VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_BUILD_TYPE Debug)


# Specify the location of the source files
set(SOURCES
    main.cpp
)

# Add the executable target
add_executable(myUsers ${SOURCES})

# Set the path to MySQL Connector/C++ libraries
link_directories(/usr/lib/x86_64-linux-gnu)

# Include directories if needed
include_directories(/usr/include)

# Link the MySQL Connector/C++ library
target_link_libraries(myUsers
    PRIVATE mysqlcppconn
)

