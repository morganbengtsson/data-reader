cmake_minimum_required(VERSION 2.8)
project(data_reader)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_BUILD_TYPE Debug)
IF(CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
ENDIF(CMAKE_COMPILER_IS_GNUCC)

# fltk
add_subdirectory(externals/fltk-1.3.3)
include_directories(externals/fltk-1.3.3)

#Rapid json
include_directories(externals/rapidjson/include)

file(GLOB SOURCE
    "*.hpp"
    "*.cpp"
)

# Main
add_executable(data_reader ${SOURCE})
target_link_libraries(data_reader fltk ${FLTK_LIBRARIES})

