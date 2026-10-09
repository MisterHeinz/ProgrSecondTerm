cmake_minimum_required(VERSION 4.4)
project(DynamicArray)

set(CMAKE_CXX_STANDARD 17)

add_executable(dynamic_array
    src/main.cpp
    src/dynamic_array.cpp
)

target_include_directories(dynamic_array PRIVATE include)
target_compile_options(dynamic_array PRIVATE -Wall -Wextra)