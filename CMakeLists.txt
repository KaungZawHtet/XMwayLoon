cmake_minimum_required(VERSION 3.12)

set(project XMwayLoon)
set(version 0.9.6)
project(${project} VERSION ${version})

#conan install . -s build_type=Debug --install-folder=cmake-build-debug
#conan install . -s build_type=Release --install-folder=cmake-build-release

set(CMAKE_CXX_STANDARD 17)


set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(vendor/projects/nlohmann_json)


list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/vendor/projects/wxWidgets/cmake-build")




if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")

    message("In debug mode")
elseif (${CMAKE_BUILD_TYPE} STREQUAL "Release")
    message("In release mode")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_DEBUG_RUNTIME OFF)


else()
    message("Error!Current build type is ${CMAKE_BUILD_TYPE}")

endif()



set(BOOST_ROOT vendor/projects/boost)
#set(BOOST_INCLUDEDIR vendor/projects/boost/build/include)
#set(BOOST_LIBRARYDIR vendor/projects/boost/build/lib)
set(BOOST_NO_SYSTEM_PATHS ON)
find_package(Boost 1.71 COMPONENTS regex REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})
#[[if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()]]

#include_directories(lib/randomizer/src/english_date.h lib/randomizer/src/global_objects.h)

# Request the required wxWidgets libs
find_package(wxWidgets 3.1.3 COMPONENTS all REQUIRED)
# Include the wxWidgets use file to initialize various settings
include(${wxWidgets_USE_FILE})
# Define a variable containing a list of source files for the project
if(${WIN32})
    # Include a RC file for windows
    list(APPEND SRC_FILES ../sample.rc)
elseif(${APPLE})
    # Add an icon for the apple .app file
    list(APPEND SRC_FILES ../../src/osx/carbon/wxmac.icns)
endif()



if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")


    #TODO:: gtest's subdirectory condition for other contributors
    add_subdirectory(vendor/projects/benchmark/googletest)
    enable_testing()
    add_subdirectory(test)

    add_subdirectory(vendor/projects/benchmark)
    add_subdirectory(benchmark)

endif()



add_subdirectory(vendor/customization)
add_subdirectory(lib/randomizer)
add_subdirectory(lib/gui)
#target_compile_options(randomizer PRIVATE -Werror -Wall -Wextra -Wsign-conversion -pedantic-errors -Wconversion)
add_subdirectory(lib/logic)
add_subdirectory(lib/model)


add_executable(${project} main.cpp)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")


elseif (${CMAKE_BUILD_TYPE} STREQUAL "Release")

    if(${APPLE})

        message("Compiler option works at Apple for exe")
        target_compile_options(${project} PRIVATE -O3 -flto=full)

    elseif(${WIN32})

        message("Compiler option works at Win32 for exe")
        target_compile_options(${project} PRIVATE -O3)
    else()

        message("Compiler option works for exe")
        target_compile_options(${project} PRIVATE -O3)
    endif()

else()
    message("Error compiler option!")

endif()


target_link_libraries(${project}
         ${wxWidgets_LIBRARIES} GUI )
