# Make - Cross Platform Makefile Generator
# Copyright 2000-2012 Kitware, Inc., Insight Software Consortium
#
# Distributed under the OSI-approved BSD License (the "License");
# see accompanying file Copyright.txt for details.
#
# This software is distributed WITHOUT ANY WARRANTY; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the License for more information.
#=============================================================================
cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)
project(c-project)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set (CMAKE_EXPORT_COMPILE_COMMANDS 1)
set (CMAKE_CXX_FLAGS_DEBUG "{CMAKE_CXX_FLAGS_DEBUG} -Wall")

#Generate ctags file
#add_custom_target(ctags
#	COMMAND ctags -o . -R --exclude=.git .)
 set(source_files
  src/fos/math/src/sqroot.c 
  src/sms/src/main.c
     )

set(test_files
  src/fos/math/test/testsqroot.cpp
     )

#set (C_PROJECT_VERSION_MAJOR 0)
#set (C_PROJECT_VERSION_MINOR 1)
#
## configure a  header file to pass some of the CMake settings to the source code
#configure_file(
#	"${PROJECT_SOURCE_DIR}/src/fos/config.h.in"
#	"${PROJECT_BINARY_DIR}/src/fos/config.h")
#
#include_directories("${PROJECT_BINARY_DIR}")

set(EXECUTABLE_OUTPUT_PATH build)

include_directories(src src/fos src/fos/math src/sms)
link_directories() 
add_executable(c-project ${source_files})
target_link_libraries(c-project m)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests ${test_files})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
