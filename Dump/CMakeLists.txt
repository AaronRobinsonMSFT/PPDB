cmake_minimum_required (VERSION 3.0)
project (PPDBDump)

include_directories (${INC})

add_executable (PPDBDump PPDBDump.cpp ${READER_SRC})
target_link_libraries (PPDBDump PPDBReader)

install(TARGETS PPDBDump DESTINATION $<CONFIG>/${CMAKE_GENERATOR_PLATFORM})
install(FILES $<TARGET_PDB_FILE:${PROJECT_NAME}> DESTINATION $<CONFIG>/${CMAKE_GENERATOR_PLATFORM} OPTIONAL)