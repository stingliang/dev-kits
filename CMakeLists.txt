# cmake minimum version requirements
cmake_minimum_required(VERSION 3.10)

# project name
project(dev-utility-library)

# assign generate path
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/build/bin)

# cpp version
set(CMAKE_CXX_STANDARD 14)

# include all source files
file(GLOB SOURCES
        ${PROJECT_SOURCE_DIR}/logger/logger.cpp
        ${PROJECT_SOURCE_DIR}/utility/utility.cpp
        )

# include list
set(INCLUDE_LIST
        ${CMAKE_SOURCE_DIR}
        )

# library list
set(LIBRARY_LIST
        # std library
        # pthread
        )

# create a library
add_library(dev-utility-library SHARED
        ${SOURCES}
        )
add_library(sting::dev ALIAS ${PROJECT_NAME})

# include libraries
target_include_directories(dev-utility-library PUBLIC
        ${INCLUDE_LIST}
        )

# link libraries
target_link_libraries(dev-utility-library PUBLIC
        ${LIBRARY_LIST}
        )

# sample
add_subdirectory(sample)