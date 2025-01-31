cmake_minimum_required(VERSION 3.10)
project(rapidjson_example)

set(CMAKAE_CXX_STANDARD 17)

# To include rapidjson
include_directories(/usr/include/rapidjson) # For apt-installed Rapidjson

add_executable(rapidjson_example main.cpp)

