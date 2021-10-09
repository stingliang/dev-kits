# cmake minimum version requirements
cmake_minimum_required(VERSION 3.10)

# project name
project(dev-utility-library)

# cpp version
set(CMAKE_CXX_STANDARD 14)

# library
add_subdirectory(core)

# sample
add_subdirectory(sample)