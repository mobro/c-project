# Add executable called "application" that is built from the source files
# in the app folder. 
set(source_files
  src/sms/src/main.c
     )


set(EXECUTABLE_OUTPUT_PATH build)

include_directories( src ../fw/src ../pf/src)

add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})

set ( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
set ( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

add_executable (application ${source_files})

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
target_link_libraries (application LINK_PUBLIC fw)
