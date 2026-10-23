cmake_minimum_required(VERSION 3.10)
project(DynamicArray)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(dynamic_array
    src/main.cpp
)

target_include_directories(dynamic_array PRIVATE include)

target_compile_options(dynamic_array PRIVATE
    -Wall -Wextra
    -fsanitize=address
    -fno-omit-frame-pointer
    -g
)

target_link_options(dynamic_array PRIVATE
    -fsanitize=address
)