add_executable(csv_generation_in_task csv_generation_in_task.cpp)
add_executable(json_generation_in_task json_generation_in_task.cpp)
add_executable(xml_generation_in_task html_generation_in_task.cpp)
add_executable(html_generation_in_task html_generation_in_task.cpp)

add_test(Name csv_generation_in_task
        COMMAND csv_generation_in_task)
add_test(Name json_generation_in_task
        COMMAND json_generation_in_task)
add_test(Name xml_generation_in_task
        COMMAND xml_generation_in_task)
add_test(Name html_generation_in_task
        COMMAND html_generation_in_task)



target_link_libraries(csv_generation_in_task gtest_main taskflow)
target_link_libraries(json_generation_in_task PUBLIC gtest_main
        PUBLIC nlohmann_json::nlohmann_json taskflow taskflow)
target_link_libraries(xml_generation_in_task gtest_main taskflow)
target_link_libraries(html_generation_in_task gtest_main taskflow)