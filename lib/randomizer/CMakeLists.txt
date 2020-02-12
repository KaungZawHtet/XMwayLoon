file(GLOB XMwayLoon_randomizer_CPPs
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/ph_number/*.cpp"
        )
add_library(randomizer
        ${XMwayLoon_randomizer_CPPs})
target_link_libraries(randomizer model customized_third_parties)

target_include_directories(randomizer
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

