cmake_minimum_required(VERSION 3.12)
project(XMwayLoon)
#CMAKE_PREFIX_PATH=~/Desktop/c++/wxWidgets/cmake-build
#conan install . -s build_type=Debug --install-folder=cmake-build-debug
#conan install . -s build_type=Release --install-folder=cmake-build-release

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(vendor/taskflow)
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(vendor/nlohmann_json)


set(BOOST_ROOT vendor/boost)
set(BOOST_INCLUDEDIR vendor/boost/build/include)
set(BOOST_LIBRARYDIR vendor/boost/build/lib)
set(BOOST_NO_SYSTEM_PATHS ON)
find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})
#[[if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()]]

#include_directories(lib/ShinMwayLoon/src/english_date.h lib/ShinMwayLoon/src/global_objects.h)



#TODO:: gtest's subdirectory condition for other contributors
add_subdirectory(vendor/benchmark/googletest)
enable_testing()
add_subdirectory(test)

add_subdirectory(vendor/benchmark)
add_subdirectory(benchmark)

#add_subdirectory(vendor/wxWidgets)


#[[file(GLOB parallel_hashmap_files
        "vendor/parallel_hashmap/*.h")
add_library(parallel_hashmap INTERFACE)
target_include_directories(parallel_hashmap INTERFACE ${parallel_hashmap_files})]]



add_subdirectory(lib/ShinMwayLoon)


# Request the required wxWidgets libs
find_package(wxWidgets 3.1.3 COMPONENTS all REQUIRED)
# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})
# Define a variable containing a list of source files for the project
if(WIN32)
    # Include a RC file for windows
    list(APPEND SRC_FILES ../sample.rc)
elseif(APPLE)
    # Add an icon for the apple .app file
    list(APPEND SRC_FILES ../../src/osx/carbon/wxmac.icns)
endif()
add_subdirectory(lib/GUI)
#target_compile_options(ShinMwayLoon PRIVATE -Werror -Wall -Wextra -Wsign-conversion -pedantic-errors -Wconversion)
add_subdirectory(lib/logic)
add_subdirectory(lib/model)


add_executable(Executable main.cpp)
target_link_libraries(Executable taskflow
         ${wxWidgets_LIBRARIES} GUI logic ${Boost_LIBRARIES})
