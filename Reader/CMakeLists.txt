cmake_minimum_required (VERSION 3.0)
project (PPDBReader)

include_directories (${INC})

add_library (PPDBReader
    CoreReader.cpp
    Streams.cpp
    Tables.cpp)