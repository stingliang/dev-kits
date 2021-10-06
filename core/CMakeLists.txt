# cmake minimum version requirements
cmake_minimum_required(VERSION 3.10)

# project name
project(sting_dev)

# include all source files
file(GLOB SOURCES
        logger/logger.cpp
        utility/utility.cpp
        asio/server.cpp
        asio/client.cpp
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
add_library(sting_dev STATIC
        ${SOURCES}
        )
add_library(sting::dev ALIAS ${PROJECT_NAME})

# include libraries
target_include_directories(sting_dev PUBLIC
        ${INCLUDE_LIST}
        )

# link libraries
target_link_libraries(sting_dev PUBLIC
        ${LIBRARY_LIST}
        )