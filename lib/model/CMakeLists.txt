file(GLOB XMwayLoon_model_CPPs
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_library(model
        ${XMwayLoon_model_CPPs})

if(${APPLE})

    message("Compiler option works at Apple for model")
    target_compile_options(model PRIVATE -O3 -flto=full)

elseif(${WIN32})

    message("Compiler option works at Win32 for model")
    target_compile_options(model PRIVATE -O3)
else()

    message("Compiler option works for model")
    target_compile_options(model PRIVATE -O3)
endif()

target_link_libraries(model PUBLIC
        randomizer customization
        )

target_include_directories(model
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

