file(GLOB XMwayLoon_model_CPPs
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(model
        ${XMwayLoon_model_CPPs})

target_link_libraries(model PUBLIC
        randomizer sqlite3 customized_third_parties
        )

target_include_directories(model
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

