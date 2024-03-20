cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)


# Create Lib
add_library(libA lib/lib_a.cpp)

# Application Executable 
add_executable(myExecutable main.cpp)
target_link_libraries(myExecutable libA)


# Unit Test Executable
# From Documentation
# GTEST_LIBRARIES - The Google Test gtest library, note it also requires linking with an appropriate thread library
find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")

add_executable(unitTest unittest/unittests.cpp)
target_link_libraries(unitTest libA ${GTEST_LIBRARIES} pthread)
