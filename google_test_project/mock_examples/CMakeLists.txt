cmake_minimum_required(VERSION 3.13)
set(CMAKE_CXX_STANDARD 14)

project(MockExamples)

# Create Lib
add_library(databaseConnectionLibrary lib/idatabase_connection.cpp)
add_library(employeeManagerLibrary lib/employee_manager.cpp)

set(ACTUAL_LIBRARIES databaseConnectionLibrary employeeManagerLibrary)

# Application Executable 
add_executable(mySecondExecutable main.cpp)
target_link_libraries(mySecondExecutable ${ACTUAL_LIBRARIES})


# GMock libs as variable
set(GMOCK_LIBRARIES C:/msys64/ucrt64/lib/libgmock.a C:/msys64/ucrt64/lib/libgmock_main.a)

# Unit Test Executable
# From Documentation
# GTEST_LIBRARIES - The Google Test gtest library, note it also requires linking with an appropriate thread library
find_package(GTest REQUIRED)
message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")

add_executable(mockUnitTest unittest/unittests.cpp)
target_link_libraries(mockUnitTest 
    ${GTEST_LIBRARIES} 
    ${GMOCK_LIBRARIES} 
    pthread 
    ${ACTUAL_LIBRARIES})