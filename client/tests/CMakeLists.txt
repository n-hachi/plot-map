FetchContent_Declare(
    catch
    GIT_REPOSITORY https://github.com/catchorg/catch2.git
    GIT_TAG v2.13.6
    )
FetchContent_MakeAvailable(catch)

# Tests need to added as executables first
add_executable(testlib testlib.cpp)

# I'm using C++17 in the test
target_compile_features(testlib PRIVATE cxx_std_11)

# Should be linked to the main library
target_link_libraries(testlib PRIVATE plotmap_client Catch2::Catch2)

# for ctest
add_test(NAME testlibtest COMMAND testlib)
