
file(GLOB customization_CPPs
        "${CMAKE_CURRENT_SOURCE_DIR}/src/customization.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/tinyxml2.cpp"
         "${CMAKE_CURRENT_SOURCE_DIR}/src/parabaik.c"
        )





add_library(customization ${customization_CPPs})


target_include_directories(customization
        PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

if(${WIN32})
    target_link_libraries(customization

            "${CMAKE_CURRENT_SOURCE_DIR}/a/windows/icu/libicudata.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/windows/icu/libicui18n.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/windows/icu/libicuio.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/windows/icu/libicutest.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/windows/icu/libicutu.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/windows/icu/libicuuc.lib"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/windows/sqlite/libsqlite3.lib"
            )

elseif(${APPLE})

    target_link_libraries(customization

            "${CMAKE_CURRENT_SOURCE_DIR}/a/mac/icu/libicudata.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/mac/icu/libicui18n.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/mac/icu/libicuio.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/mac/icu/libicutest.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/mac/icu/libicutu.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/mac/icu/libicuuc.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/mac/sqlite/libsqlite3.a"
            )
else()

    target_link_libraries(customization

            "${CMAKE_CURRENT_SOURCE_DIR}/a/ubuntu/icu/libicudata.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/ubuntu/icu/libicui18n.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/ubuntu/icu/libicuio.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/ubuntu/icu/libicutest.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/ubuntu/icu/libicutu.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/ubuntu/icu/libicuuc.a"
            "${CMAKE_CURRENT_SOURCE_DIR}/a/ubuntu/sqlite/libsqlite3.a"
            )
endif()

