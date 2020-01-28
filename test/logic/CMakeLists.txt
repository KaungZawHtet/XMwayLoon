add_executable(csv_generation_in_task csv_generation_in_task.cpp)
add_executable(json_test json_test.cpp)
add_executable(xml_generation_in_task html_generation_in_task.cpp)
add_executable(html_generation_in_task html_generation_in_task.cpp)
add_executable(file_test file_test.cpp)
add_executable(general_test general_test.cpp)


add_test(Name csv_generation_in_task
        COMMAND csv_generation_in_task)
add_test(Name json_test
        COMMAND json_test)
add_test(Name xml_generation_in_task
        COMMAND xml_generation_in_task)
add_test(Name html_generation_in_task
        COMMAND html_generation_in_task)
add_test(Name file_test
        COMMAND file_test)
add_test(Name general_test
        COMMAND general_test)

message("${Boost_LIBRARIES}")

target_link_libraries(csv_generation_in_task gtest_main logic model)
target_link_libraries(json_test PUBLIC gtest_main logic model nlohmann_json::nlohmann_json)
target_link_libraries(xml_generation_in_task gtest_main logic model)
target_link_libraries(html_generation_in_task gtest_main logic model)
target_link_libraries(file_test gtest_main customized_third_parties sqlite3)
target_link_libraries(general_test gtest_main ${Boost_LIBRARIES} customized_third_parties)