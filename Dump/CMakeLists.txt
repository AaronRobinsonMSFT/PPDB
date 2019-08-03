cmake_minimum_required (VERSION 3.0)
project (PPDBDump)

include_directories (${INC})

add_executable (PPDBDump PPDBDump.cpp)
target_link_libraries (PPDBDump PPDBReader)

install(TARGETS PPDBDump DESTINATION $<CONFIG>/${CMAKE_GENERATOR_PLATFORM})

if (WIN32)
    install(FILES $<TARGET_PDB_FILE:${PROJECT_NAME}> DESTINATION $<CONFIG>/${CMAKE_GENERATOR_PLATFORM} OPTIONAL)
endif()