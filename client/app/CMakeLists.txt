# Commandline parser library
FetchContent_Declare(
    clilib
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v1.9.0
    )
FetchContent_MakeAvailable(clilib)

add_executable(
    plog-map-client.exe
    main.cpp
    )

target_compile_features(
    plog-map-client.exe
    PRIVATE cxx_std_11
    )
