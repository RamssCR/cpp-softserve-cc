cmake_minimum_required(VERSION 4.1)
project(CppCC)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(CppCC main.cpp)

target_include_directories(CppCC PUBLIC include)
target_compile_options(CppCC PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -g
        -O0
)