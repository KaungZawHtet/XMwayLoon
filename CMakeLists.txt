cmake_minimum_required(VERSION 3.12)
project(FakeDataGenerator)

set(CMAKE_CXX_STANDARD 17)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()





add_executable(FakeDataGenerator main.cpp
        lib/FakeDataGeneration/src/english_date.cpp
        lib/FakeDataGeneration/src/english_date.h)