file(GLOB ShinMwayLoon_CPPs
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(ShinMwayLoon
        ${ShinMwayLoon_CPPs})


target_include_directories(ShinMwayLoon
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

