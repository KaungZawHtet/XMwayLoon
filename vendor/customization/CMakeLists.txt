
file(GLOB customization_CPPs
        "${CMAKE_CURRENT_SOURCE_DIR}/src/customization.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/tinyxml2.cpp"
         "${CMAKE_CURRENT_SOURCE_DIR}/src/parabaik.c"
        )





add_library(customization ${customization_CPPs})


if(${APPLE})

    message("Compiler option works at Apple for customization")
    target_compile_options(customization PRIVATE -O3 -flto=full)

elseif(${WIN32})

    message("Compiler option works at Win32 for customization")
    target_compile_options(customization PRIVATE -O3)
else()

    message("Compiler option works for customization")
    target_compile_options(customization PRIVATE -O3)
endif()


target_include_directories(customization
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(${WIN32})
    target_link_libraries(customization

            "${CMAKE_CURRENT_SOURCE_DIR}/a/icu/libicudata.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/icu/libicui18n.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/icu/libicuio.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/icu/libicutest.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/icu/libicutu.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/icu/libicuuc.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/sqlite/libsqlite3.lib"
            )

elseif(${UNIX})

    target_link_libraries(customization
            "${CMAKE_CURRENT_SOURCE_DIR}/a/icu/libicui18n.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/icu/libicuio.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/icu/libicutest.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/icu/libicutu.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/icu/libicuuc.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/icu/libicudata.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/sqlite/libsqlite3.a"
            )
endif()