set(LIB_NAME SharedLib)

#collect everything within this folder
file(GLOB LIB_SRC_FILES 
	*.cpp 
	*.h
)

add_library(${LIB_NAME} SHARED
	${LIB_SRC_FILES}
)

target_include_directories(${LIB_NAME} INTERFACE 
	${CMAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(${LIB_NAME} INTERFACE
)

target_compile_definitions(${LIB_NAME} PRIVATE SHAREDLIB_COMPILING)

add_library(${LIB_NAME}::${LIB_NAME} ALIAS ${LIB_NAME})
