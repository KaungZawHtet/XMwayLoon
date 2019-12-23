file(GLOB XMwayLoon_logic_CPPs
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(logic
        ${XMwayLoon_logic_CPPs})

target_link_libraries(logic PUBLIC nlohmann_json::nlohmann_json
        taskflow
        ShinMwayLoon
        model
        )
target_include_directories(logic
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

