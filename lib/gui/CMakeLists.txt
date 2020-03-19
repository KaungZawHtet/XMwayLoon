file(GLOB XMwayLoon_GUI_main_CPPs
        ${CMAKE_CURRENT_SOURCE_DIR}/src/app.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main_frame.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/preference_dialog.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_loader.cpp
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
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/input_validator.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/read_me_dialog.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/read_me_panel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/data_generation/gen_info_packaging.cpp
        )



file(GLOB XMwayLoon_GUI_type_extension_CPPs
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_extension/extend_page.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_extension/extension_manually_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_extension/extension_by_file_container.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_extension/extension_manually_event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_extension/extension_by_file_event.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_extension/read_me_dialog.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/type_extension/read_me_panel.cpp

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


if(${APPLE})

    message("Compiler option works at Apple for GUI")
    target_compile_options(GUI PRIVATE -O3 -flto=full)

elseif(${WIN32})

    message("Compiler option works at Win32 for GUI")
    target_compile_options(GUI PRIVATE -O3)
else()

    message("Compiler option works for GUI")
    target_compile_options(GUI PRIVATE -O3)
endif()

target_link_libraries(GUI PRIVATE logic model ${wxWidgets_LIBRARIES})


target_include_directories(GUI
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
