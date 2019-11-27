file(GLOB ShinMwayLoon_CPPs
        "${CMAKE_CURRENT_SOURCE_DIR}/ShinMwayLoon/src/*.cpp")
add_library(ShinMwayLoon
        ${ShinMwayLoon_CPPs})


target_include_directories(ShinMwayLoon
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/ShinMwayLoon/include")

message(${CMAKE_CURRENT_SOURCE_DIR})