set(LIB_NAME StaticLib)

# collect everything within this folder
file(GLOB LIB_SRC_FILES 
	*.cpp 
	*.h
)

# create STATIC library with collected files
add_library(${LIB_NAME} STATIC
	${LIB_SRC_FILES}
)

# add the parent folder of this one as an include directory for any project that uses this library
# INTERFACE means this include is only visible for projects including this library but not for the library itself
# PUBLIC everyone can see the includes
# PRIVATE includes are only visible within the library
target_include_directories(${LIB_NAME} INTERFACE 
	${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(${LIB_NAME} INTERFACE
)

# add an alias, following the CMake package naming convention Name::Name
add_library(${LIB_NAME}::${LIB_NAME} ALIAS ${LIB_NAME})
