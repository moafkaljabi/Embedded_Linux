cmake_minimum_required(VERSION 3.16)

project(MySQL_DB VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the location of the source files
file(GLOB_RECURSE SOURCES
    src/*.cpp
    MySQLHandler/*.cpp
    MySQLHandler/connectToDatabase/*.cpp
    addRecord/*.cpp
    deleteRecord/*.cpp
    updateRecord/*.cpp
    readRecords/*.cpp
)

# Add the executable target
add_executable(appMySQL_DB ${SOURCES})

# Specify the include directories and libraries manually
include_directories("/usr/include")
link_directories("/usr/lib/x86_64-linux-gnu")

# Link the MySQL Connector/C++ library
target_link_libraries(appMySQL_DB
    PRIVATE mysqlcppconn
)

# Install rules (optional)
include(GNUInstallDirs)
install(TARGETS appMySQL_DB
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
