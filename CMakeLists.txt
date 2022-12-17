cmake_minimum_required(VERSION 3.20)
project(zmq-wrappers)

set(CMAKE_CXX_STANDARD 14)

# find dependencies
find_package(Boost COMPONENTS filesystem thread)
find_package(GTest REQUIRED)

# create library
add_library(zmq-wrappers
    src/templates/basic_thread.cpp
)

# include directory is installed with the dev package
# src directory is included as a private include
target_include_directories(zmq-wrappers PUBLIC include)
target_include_directories(zmq-wrappers PRIVATE src)

# Test constructs
enable_testing()
add_subdirectory(test)
