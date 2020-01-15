

add_executable(TypeCheckTest type_compare_test.cpp)

add_test(Name TypeCheckTest
        COMMAND TypeCheckTest)

target_link_libraries(TypeCheckTest gtest_main model ${Boost_LIBRARIES} ${wxWidgets_LIBRARIES})