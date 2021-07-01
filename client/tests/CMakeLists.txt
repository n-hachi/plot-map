FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
    )
FetchContent_MakeAvailable(googletest)

# GoogleTest requires at least c++11
set(CMAKE_CXX_STANDARD 11)

enable_testing()

# Function to add passed test name as an executable file to the target of ctest
function (add_gtest_target test_name)
    add_executable(${test_name} ${test_name}.cpp)
    target_link_libraries(${test_name}
        plotmap_client
        gtest_main
        )
    add_test(
        NAME ${test_name}
        COMMAND ./${test_name}
        )
endfunction()

# Append test file into following array
set(gtest_targets
    testlib
    )

foreach(target ${gtest_targets})
    add_gtest_target(${target})
endforeach()
