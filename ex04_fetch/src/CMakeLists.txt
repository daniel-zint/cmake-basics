# I like to set an exec name. It is much easier to change afterwards.
set(EXEC_NAME ${PROJECT_NAME})	# set exec name to the project name

# create a new target
add_executable(${EXEC_NAME}
	main.cpp
)

# add includes to your target
target_include_directories(${EXEC_NAME} PUBLIC
)

# add libs to your target
target_link_libraries(${EXEC_NAME} PRIVATE
	CLI11::CLI11
)

# request features from the compiler
target_compile_features(${EXEC_NAME} PRIVATE cxx_std_17)