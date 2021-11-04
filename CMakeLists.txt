# cmake minimum version requirements
cmake_minimum_required(VERSION 3.0)

# project name
project(dev-utility-library)

# cpp version
set(CMAKE_CXX_STANDARD 14)

# ignore warnings related Boost version
set(Boost_NO_WARN_NEW_VERSIONS ON)

# library
add_subdirectory(core)

# sample
add_subdirectory(sample)