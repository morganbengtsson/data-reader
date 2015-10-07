cmake_minimum_required(VERSION 2.8)
project(data_reader)

# fltk
add_subdirectory(externals/fltk-1.3.3)
include_directories(externals/fltk-1.3.3)

file(GLOB SOURCE
    "*.hpp"
    "*.cpp"
)

# Main
add_executable(data_reader ${SOURCE})
target_link_libraries(data_reader fltk ${FLTK_LIBRARIES})

