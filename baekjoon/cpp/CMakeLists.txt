cmake_minimum_required(VERSION 3.20)
project(baekjoon_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB CPP_FILES "solutions/*.cpp")
foreach(CPP_FILE ${CPP_FILES})
    get_filename_component(TARGET_NAME ${CPP_FILE} NAME_WE)
    add_executable(${TARGET_NAME} ${CPP_FILE})
endforeach()
