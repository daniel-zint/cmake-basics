# set a minimal CMake version
cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

if( CMAKE_SOURCE_DIR MATCHES " " )
	message( WARNING "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( WARNING "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

# write all libs and executables in one directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# project name
get_filename_component( PROJ_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJ_NAME} CXX)
# the project name can be later called with ${PROJECT_NAME}

# set C++ standard (you can also set the standard specifically for a target)
#set (CMAKE_CXX_STANDARD 17)
#set (CMAKE_CXX_STANDARD_REQUIRED True)
# position independent code is required for shared libs. For GCC this is -fPIC
set (CMAKE_POSITION_INDEPENDENT_CODE ON)

# hide ALL_BUILD and ZERO_CHECK
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# This example has the fetch_content for CLI11 stored in the cmake folder
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

########## libraries ##########
include(cli11)

########## executables and other targets ##########
add_subdirectory(src)