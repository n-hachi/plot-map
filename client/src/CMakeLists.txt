# Commandline parser library
FetchContent_Declare(
    rapidxml
    URL https://sourceforge.net/projects/rapidxml/files/rapidxml/rapidxml%201.13/rapidxml-1.13.zip/download
    )
FetchContent_MakeAvailable(rapidxml)

set(HEADER_LIST
    "${PROJECT_SOURCE_DIR}/include/plot/xml.hpp"
    "${PROJECT_SOURCE_DIR}/include/plot/lib.hpp"
    )

# Make an automatic library
add_library(plotmap_client
    xml.cpp
    lib.cpp
    ${HEADER_LIST}
    )

# This library depends repositories include and rapidxml
target_include_directories(plotmap_client PUBLIC
    ../include
    ${rapidxml_SOURCE_DIR}
    )

# This depends on (header only) boost
target_link_libraries(plotmap_client PRIVATE Boost::boost)

# All users of this library will need at least C++11
target_compile_features(plotmap_client PUBLIC cxx_std_11)
