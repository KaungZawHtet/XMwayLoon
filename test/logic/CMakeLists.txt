add_executable(CSVTest csv_test.cpp)
add_executable(JSONTest json_test.cpp)
add_executable(XMLTest xml_test.cpp)
add_executable(HTMLTest html_test.cpp)
add_executable(FileTest file_test.cpp)
add_executable(GeneralLogicTest general_test.cpp)
add_executable(ParallelTest parallel_test.cpp)

add_test(Name CSVTest
        COMMAND CSVTest)
add_test(Name JSONTest
        COMMAND JSONTest)
add_test(Name XMLTest
        COMMAND XMLTest)
add_test(Name HTMLTest
        COMMAND HTMLTest)
add_test(Name FileTest
        COMMAND FileTest)
add_test(Name GeneralLogicTest
        COMMAND GeneralLogicTest)
add_test(Name ParallelTest
        COMMAND ParallelTest)


message("${Boost_LIBRARIES}")

target_link_libraries(CSVTest gtest_main logic model  ${CMAKE_DL_LIBS})
target_link_libraries(JSONTest PUBLIC gtest_main logic model nlohmann_json::nlohmann_json  ${CMAKE_DL_LIBS})
target_link_libraries(XMLTest gtest_main logic model  ${CMAKE_DL_LIBS})
target_link_libraries(HTMLTest gtest_main logic model)
target_link_libraries(FileTest gtest_main customization sqlite3  ${CMAKE_DL_LIBS})
target_link_libraries(GeneralLogicTest gtest_main ${Boost_LIBRARIES} customization  ${CMAKE_DL_LIBS})
target_link_libraries(ParallelTest gtest_main ${Boost_LIBRARIES} customization  ${CMAKE_DL_LIBS})