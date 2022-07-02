cmake_minimum_required(VERSION 3.17)
project(ProjectGame)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(ProjectGame_run ${SOURCE_FILES})

include_directories(ProjectGame_lib)
add_subdirectory(ProjectGame_lib)

target_link_libraries(ProjectGame_run ProjectGame_lib)

add_subdirectory(Google_tests)