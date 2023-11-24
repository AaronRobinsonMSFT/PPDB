cmake_minimum_required (VERSION 3.10)
project (PPDB)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set (INC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

add_subdirectory (Dump)
add_subdirectory (Reader)