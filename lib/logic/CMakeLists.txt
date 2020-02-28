file(GLOB XMwayLoon_logic_CPPs
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/generation_task_manager/*.cpp"
        )
add_library(logic
        ${XMwayLoon_logic_CPPs})

target_link_libraries(logic PUBLIC nlohmann_json::nlohmann_json
        customized_third_parties
        randomizer
        model

        )
target_include_directories(logic
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

