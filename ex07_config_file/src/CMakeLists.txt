# I like to set an exec name. It is much easier to change afterwards.
set(EXEC_NAME ${PROJECT_NAME})	# set exec name to the project name

set(float_type "float")
configure_file(cmakeConfig.h.in cmakeConfig.h)

# create a new target
add_executable(${EXEC_NAME}
	main.cpp
)

# add includes to your target
target_include_directories(${EXEC_NAME} PRIVATE
	${CMAKE_CURRENT_BINARY_DIR}		# this is the directory where the config file is placed
)

if(glog_FOUND)
	# add libs to your target
	target_link_libraries(${EXEC_NAME} PRIVATE glog::glog)
	target_compile_definitions(${EXEC_NAME} PRIVATE USE_GLOG)
endif()

# request features from the compiler
target_compile_features(${EXEC_NAME} PRIVATE cxx_std_17)