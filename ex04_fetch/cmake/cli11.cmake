if(TARGET CLI11::CLI11)
    return()
endif()

find_package(CLI11 QUIET)

if(NOT CLI11_FOUND)
    message(STATUS "Download and create target 'CLI11::CLI11'")
    include(FetchContent)
    FetchContent_Declare(
        cli11
        GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
        GIT_TAG a6c48261d4fb62b232c46277acbcc3d14d5b7e14
    )
    FetchContent_MakeAvailable(cli11)
    set_target_properties(CLI11 PROPERTIES FOLDER libs)
else()
    message(STATUS "CLI11 found")
endif()