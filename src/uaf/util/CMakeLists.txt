# uaf/src/util/CMakeLists.txt

# Add all source files in this directory.
aux_source_directory(. UTIL_SOURCES)

# Create a shared library consisting of the previously added source files.
add_library(uafutil SHARED ${UTIL_SOURCES})

# Link the libraries.
if (WIN32)
    target_link_libraries(uafutil 
                          ${OPENSSL_LIBRARIES}
                          ${LIBXML2_LIBRARIES}
                          oleaut32 ole32 Version ws2_32 rpcrt4 crypt32 
                          uabase uapki uastack xmlparser )
else (WIN32)
    target_link_libraries(uafutil
                          ${OPENSSL_LIBRARIES}
                          ${LIBXML2_LIBRARIES}
                          dl rt pthread
                          uabase uapki uastack xmlparser )
endif (WIN32)