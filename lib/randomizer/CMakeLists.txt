file(GLOB XMwayLoon_randomizer_CPPs
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/ph_number/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/name/*.cpp"
        )
add_library(randomizer
        ${XMwayLoon_randomizer_CPPs})


target_compile_options(randomizer PRIVATE -O3)


target_link_libraries(randomizer model customization ${Boost_LIBRARIES})

target_include_directories(randomizer
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

