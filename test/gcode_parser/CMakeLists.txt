cmake_minimum_required(VERSION 3.2)
project(test_gcode CXX)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_STANDARD 11)

include_directories(include)
file(GLOB GCODE_SRC_FILES "src/gcode/*.cc")
add_executable(${PROJECT_NAME} "src/main.cc" ${GCODE_SRC_FILES})
