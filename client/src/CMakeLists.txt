# Commandline parser library
FetchContent_Declare(
    rapidxml
    URL https://sourceforge.net/projects/rapidxml/files/rapidxml/rapidxml%201.13/rapidxml-1.13.zip/download
    )
FetchContent_MakeAvailable(rapidxml)


# Make an automatic library
add_library(plotmap_client lib.cpp)

# This depends on (header only) boost
target_link_libraries(plotmap_client PRIVATE Boost::boost)

# All users of this library will need at least C++11
target_compile_features(plotmap_client PUBLIC cxx_std_11)
