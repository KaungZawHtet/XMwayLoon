file(GLOB XMwayLoon_GUI_CPPs
    ${CMAKE_CURRENT_SOURCE_DIR}/src/app.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main_frame.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/gen_panel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/type_list.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/extend_panel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/type_grid.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/type_generation.cpp




        )
add_library(GUI
    ${XMwayLoon_GUI_CPPs})


target_include_directories(GUI
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
