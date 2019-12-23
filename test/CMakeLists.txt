
cmake_minimum_required(VERSION 3.12)

#TODO: consider this
#set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)


add_executable(NumberTest number_test.cpp)
add_executable(PhNumTest ph_num_test.cpp)
add_executable(DateTest date_test.cpp)
add_executable(PangramTest pangram_test.cpp)
add_executable(GeneralTest general_test.cpp)
add_executable(BooleanTest boolean_test.cpp)
#add_executable(EnglishDateTest english_date_old_test.cpp)

#target_compile_options(DateTest -Werror -Wextra -Wshadow -Wnon-virtual-dtor -pedantic)



add_test(Name NumberTest
        COMMAND NumberTest)
add_test(Name PhNumTest
        COMMAND PhNumTest)
add_test(Name DateTest
        COMMAND DateTest)
add_test(Name PangramTest
        COMMAND PangramTest)
add_test(Name PangramTest
        COMMAND PangramTest)
add_test(Name GeneralTest
        COMMAND GeneralTest)
add_test(Name BooleanTest
        COMMAND BooleanTest)
#add_test(Name EnglishDateTest COMMAND EnglishDateTest)


target_link_libraries(NumberTest gtest_main ShinMwayLoon)
target_link_libraries(PhNumTest gtest_main ShinMwayLoon)
target_link_libraries(DateTest gtest_main ShinMwayLoon)
target_link_libraries(PangramTest gtest_main ShinMwayLoon)
target_link_libraries(GeneralTest gtest_main ShinMwayLoon)
target_link_libraries(BooleanTest gtest_main ShinMwayLoon)
#target_link_libraries(EnglishDateTest gtest_main ShinMwayLoon)