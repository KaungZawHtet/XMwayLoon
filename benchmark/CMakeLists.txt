cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)


add_executable(date_benchmark date_benchmark.cpp)

target_link_libraries(date_benchmark benchmark ShinMwayLoon)