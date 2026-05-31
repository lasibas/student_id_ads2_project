cmake_minimum_required(VERSION 3.5)
project(student_id_ads2_project C)

set(CMAKE_C_STANDARD 11)
set(SOURCES
    demo.c
    src/array.c
    src/file_utils.c
    src/linked_lists.c
    src/string_utils.c
)

add_executable(demo ${SOURCES})

# Install target (optional)
install(TARGETS demo DESTINATION bin)

# Add Bonus subdirectory for DSA demo
add_subdirectory(Bonus)
