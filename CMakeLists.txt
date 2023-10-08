cmake_minimum_required(VERSION 3.27)
project(lista-estruturas-project LANGUAGES CXX VERSION 0.0.1)
#
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
add_library(lista-estruturas INTERFACE)
add_executable(${PROJECT_NAME} src/main.cc)
target_include_directories(${PROJECT_NAME} PUBLIC include)