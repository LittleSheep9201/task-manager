cmake_minimum_required(VERSION 3.16)
project(TaskManager CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

include_directories(include)

add_executable(task_manager
    src/main.cpp
    src/TaskManager.cpp
    src/FileIO.cpp
)