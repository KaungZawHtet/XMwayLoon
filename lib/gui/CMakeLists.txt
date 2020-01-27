file(GLOB XMwayLoon_GUI_main_CPPs
        ${CMAKE_CURRENT_SOURCE_DIR}/src/app.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main_frame.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/preference_dialog.cpp

        )

file(GLOB XMwayLoon_GUI_data_generation_CPPs
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/generate_page.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/type_grid.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/type_generation_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/encoding_type_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/output_format_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/output_amount_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/generated_file_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/type_scale_event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/generate_event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/encoding_type_event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/validate_gen_info.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/input_validator.cpp)

file(GLOB XMwayLoon_GUI_type_extension_CPPs
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_extension/extend_page.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_extension/extension_manually_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_extension/extension_by_file_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_extension/extension_manually_event.cpp

        )


file(GLOB XMwayLoon_GUI_type_CPPs
        ${CMAKE_CURRENT_SOURCE_DIR}/src/grid_row/setter_numeric_level_3.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/grid_row/setter_alphanumeric_level_3.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/grid_row/setter_below_level_3.cpp
        )

add_library(GUI
        ${XMwayLoon_GUI_main_CPPs}
        ${XMwayLoon_GUI_data_generation_CPPs}
        ${XMwayLoon_GUI_type_extension_CPPs}
        ${XMwayLoon_GUI_type_CPPs})

target_link_libraries(GUI PRIVATE logic model)


target_include_directories(GUI
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
