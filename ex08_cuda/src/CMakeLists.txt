add_subdirectory(DMO)

add_subdirectory(ex01_Basic_cpu)

if(DMO_USE_CUDA)
    add_subdirectory(ex01_Basic)
endif()