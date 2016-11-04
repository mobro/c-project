# Create a library called "fw" which includes the framework source files.
 set(source_files
  src/fos/math/src/sqroot.c 
  src/fos/corefnct/math/src/fw_multiplication.c 
     )

set(test_files
  src/fos/math/test/testsqroot.cpp
  src/fos/corefnct/math/test/testsmultiplication.cpp
     )

include_directories( src )

set(EXECUTABLE_OUTPUT_PATH build)

# The extension is already found. Any number of sources could be listed here.
add_library (fw ${source_files})

# Make sure the compiler can find include files for the framework library
# when other libraries or executables link to Hello
target_include_directories (fw PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(fw m gcov)
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests ${test_files})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread gcov)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    find_package(PythonInterp)
    INCLUDE(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage runTests coverage)
    setup_target_for_coverage_cobertura(${PROJECT_NAME}_cobertura runTests coverage)
    #setup_target_for_coverage(fccov-transcoder fctest fccov --run_test=Transcoder)
    #setup_target_for_coverage(fccov-loopfile fctest fccov --run_test=ImportExport)
    #setup_target_for_coverage(fccov-messages fctest fccov --run_test=Messages)
endif (CMAKE_BUILD_TYPE STREQUAL "Debug")
