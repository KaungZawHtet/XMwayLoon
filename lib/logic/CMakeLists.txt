file(GLOB XMwayLoon_logic_CPPs
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/generation_task_manager/*.cpp"
        )
add_library(logic
        ${XMwayLoon_logic_CPPs})

if(${APPLE})

    message("Compiler option works at Apple for logic")
    target_compile_options(logic PRIVATE -O3 -flto=full)

elseif(${WIN32})

    message("Compiler option works at Win32 for logic")
    target_compile_options(logic PRIVATE -O3)
else()

    message("Compiler option works for logic")
    target_compile_options(logic PRIVATE -O3)
endif()


target_link_libraries(logic PUBLIC nlohmann_json::nlohmann_json
        customization
        randomizer
        model

        )
target_include_directories(logic
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

