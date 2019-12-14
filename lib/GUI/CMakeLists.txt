file(GLOB XMwayLoon_GUI_CPPs
        ${CMAKE_CURRENT_SOURCE_DIR}/src/app.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main_frame.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/generate_page.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/extend_page.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_grid.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_generation_panel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/encoding_type_panel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/output_format_panel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/output_amount_panel.cpp


        )
add_library(GUI
        ${XMwayLoon_GUI_CPPs})


target_include_directories(GUI
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
