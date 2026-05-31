cmake_minimum_required(VERSION 3.5)

# DSA Demo executable (Bonus)
add_executable(dsa_demo
    ${CMAKE_CURRENT_SOURCE_DIR}/DSA-Demo.c
    ${CMAKE_SOURCE_DIR}/src/Dataset_Analysis.c
    ${CMAKE_SOURCE_DIR}/src/file_utils.c
    ${CMAKE_SOURCE_DIR}/src/string_utils.c
)

target_include_directories(dsa_demo PRIVATE ${CMAKE_SOURCE_DIR}/include)

set_target_properties(dsa_demo PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output
)
