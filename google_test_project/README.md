Mingw G++ and GTest in Visual Studio Code or Windows

Setup Code
- Installing Visual Studio Code
- Installing MingW Tools https://code.visualstudio.com/docs/cpp/config-mingw (add to PATH)
  - Stop when selecting compiler and continue with CMake https://code.visualstudio.com/docs/cpp/cmake-linux
- Installing CMake https://cmake.org/download/ (add to PATH)
- Installing C++ Extension
- Installing CMake Extension


Setup Default Project
- Create main.cpp file
- Create CMakeLists.txt
- VS Code Navigation Bar "> CMake: Configure" -> Select "MinGW G++"
- CMake generation starts
- Can be done manually as well (mkdir build + cmake -G "MinGW Makefiles")

Setup GTest
- Download Gtest Repository
- Create Build Folder
- cmake -G "MinGW Makefiles" 
- mingw32-make
- Copy all Libs (libgmock.a, libgmock-main.a, libgtest.a, libgtest_main.a) to Compiler lib (C:\msys64\ucrt64\lib)
- googlemock/include complete gmock directory to Compiler include (C:\msys64\ucrt64\include)
- googletest/include complete gtest directory to Compiler include (C:\msys64\ucrt64\include)

Add GTest to CMakeLists.txt
- find_package(GTest REQUIRED)
- message("GTest_INCLUDE_DIRS = ${GTest_INCLUDE_DIRS}")
- target_link_libraries(myExecutable ${GTEST_LIBRARIES} pthread)

Add GTest to main.cpp
- #include <gtest/gtest.h>
- TEST(TestSample, TestAddition)
  {
    ASSERT_EQ(2, add(1,1));
  }

Add GMock to CMakeLists.txt
- no find package available
- set variable
- set(GMOCK_LIBRARIES C:\msys64\ucrt64\lib\libgmock.a C:\msys64\ucrt64\lib\libgmock_main.a )