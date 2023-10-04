cmake_minimum_required(VERSION 3.27)
project(lista-estruturas-project LANGUAGES CXX VERSION 0.0.1)
#
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ====== configure project with header only library ======
add_library(lista-estruturas INTERFACE)
target_include_directories(lista-estruturas INTERFACE include/)