cmake_minimum_required(VERSION 3.12)
project(FakeDataGenerator)



set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

#include_directories(lib/FakeDataGeneration/src/english_date.h lib/FakeDataGeneration/src/global_objects.h)

add_library(FakeDataGeneratorLib
        lib/FakeDataGeneration/src/english_date.cpp
        lib/FakeDataGeneration/src/ph_number.cpp
        lib/FakeDataGeneration/src/CSVwriter.cpp
        lib/FakeDataGeneration/src/inserter.cpp
        )

add_executable(Executable main.cpp)

target_link_libraries(Executable FakeDataGeneratorLib)