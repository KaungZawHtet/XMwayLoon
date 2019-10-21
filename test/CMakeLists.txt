
cmake_minimum_required(VERSION 3.12)

#TODO: consider this
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)


add_executable(NumberTest number_test.cpp)
add_executable(PhNumTest ph_num_test.cpp)

target_link_libraries(NumberTest gtest_main)
target_link_libraries(PhNumTest gtest_main)

#[[
add_test(Name NumberTest
        COMMAND NumberTest

        )
add_test(Name PhNumTest
        COMMAND PhNumTest

        )]]
