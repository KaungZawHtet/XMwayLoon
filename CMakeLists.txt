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

#include_directories(lib/ShinMwayLoon/src/english_date.h lib/ShinMwayLoon/src/global_objects.h)



#TODO:: gtest's subdirectory condition
add_subdirectory(lib/googletest)
enable_testing()
add_subdirectory(test)


add_library(FakeDataGeneratorLib
        lib/ShinMwayLoon/src/english_date.cpp
        lib/ShinMwayLoon/src/ph_number.cpp
        lib/ShinMwayLoon/src/CSVwriter.cpp
        lib/ShinMwayLoon/src/inserter.cpp
        lib/ShinMwayLoon/src/number.cpp
        lib/ShinMwayLoon/src/name.cpp
        lib/ShinMwayLoon/src/pangram.cpp
        )
add_executable(Executable main.cpp)
target_link_libraries(Executable FakeDataGeneratorLib)
