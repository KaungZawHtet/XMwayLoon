cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 17)


add_executable(date_benchmark english_date_benchmark.cpp)
add_executable(efficiency_experiment efficiency_experiment.cpp)

target_link_libraries(date_benchmark benchmark ShinMwayLoon)
#target_compile_options(date_benchmark PRIVATE -O3)

target_link_libraries(efficiency_experiment benchmark)