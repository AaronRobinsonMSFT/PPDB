cmake_minimum_required (VERSION 3.0)
project (CorSym)

include_directories (${INC})

add_library (CorSym SHARED CorSym.cpp)
target_link_libraries (CorSym PPDBReader)

install(TARGETS CorSym DESTINATION $<CONFIG>/${CMAKE_GENERATOR_PLATFORM})

if (WIN32)
    install(FILES $<TARGET_PDB_FILE:${PROJECT_NAME}> DESTINATION $<CONFIG>/${CMAKE_GENERATOR_PLATFORM} OPTIONAL)
endif()