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



#TODO:: gtest's subdirectory condition for other contributors
add_subdirectory(vendor/benchmark/googletest)
enable_testing()
add_subdirectory(test)

add_subdirectory(vendor/benchmark)
add_subdirectory(benchmark)

file(GLOB parallel_hashmap_files
        "vendor/parallel_hashmap/*.h")
add_library(parallel_hashmap INTERFACE)
target_include_directories(parallel_hashmap INTERFACE ${parallel_hashmap_files})



file(GLOB XMwayloon
        "lib/ShinMwayLoon/src/*.cpp")
add_library(ShinMwayLoon
        ${XMwayloon})
#target_compile_options(ShinMwayLoon PRIVATE -Werror -Wall -Wextra -Wsign-conversion -pedantic-errors -Wconversion)


add_executable(Executable main.cpp)
target_link_libraries(Executable ShinMwayLoon parallel_hashmap)
