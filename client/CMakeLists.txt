cmake_minimum_required(VERSION 3.11)

# TODO
# Edit following cproject-name
project(
    plog-map-client
    VERSION 1.0
    DESCRIPTION "Sample cpp project"
    LANGUAGES CXX
    )

# FetchContent add in CMak 3.11, download during the configure step
include(FetchContent)

# FetchContent_MakeAfailable was not added until CMake 3.14; use our shim
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()

# Only do following if this is the main project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Testing only available if this is the main app
    include(CTest)

    # The Executable code
    add_subdirectory(app)

endif()
