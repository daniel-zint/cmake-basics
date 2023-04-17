set(EXEC_NAME ex01_vcpkg)

add_executable(${EXEC_NAME}
	main.cpp
)

target_include_directories(${EXEC_NAME} PRIVATE
)

target_link_libraries(${EXEC_NAME} PRIVATE
    ${SRC}
)