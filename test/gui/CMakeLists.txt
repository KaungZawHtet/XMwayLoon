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

add_executable(TypeCheckTest type_compare_test.cpp)

add_test(Name TypeCheckTest
        COMMAND TypeCheckTest)

target_link_libraries(TypeCheckTest gtest_main model ${Boost_LIBRARIES} ${wxWidgets_LIBRARIES})