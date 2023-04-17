set(LIB_NAME StaticLib)

#collect everything within this folder
file(GLOB LIB_SRC_FILES 
	*.cpp 
	*.h
)

add_library(${LIB_NAME} STATIC
	${LIB_SRC_FILES}
)

target_include_directories(${LIB_NAME} INTERFACE 
	${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(${LIB_NAME} INTERFACE
)

add_library(${LIB_NAME}::${LIB_NAME} ALIAS ${LIB_NAME})
