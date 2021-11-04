# cmake minimum version requirements
cmake_minimum_required(VERSION 3.10)

# project name
project(DEV-KITS VERSION "0.1.0")
set(DEV_KITS_CMAKE_DIR "${CMAKE_CURRENT_LIST_DIR}/../cmake")
list(APPEND CMAKE_MODULE_PATH ${DEV_KITS_CMAKE_DIR})

# options
include(options)
configure_project()
# boost dependencies
include(boost)

# include all source files
file(GLOB SOURCE_FILES
        logger/logger.cpp
        utility/utility.cpp
        asio/server.cpp
        asio/client.cpp
        )

# include list
set(INCLUDE_LIST ${CMAKE_CURRENT_SOURCE_DIR})

# create a static library
add_library(dev_kits STATIC ${SOURCE_FILES})

# include libraries
target_include_directories(dev_kits PUBLIC ${INCLUDE_LIST} ${Boost_INCLUDE_DIRS})

# link libraries
target_link_libraries(dev_kits PUBLIC ${LIBRARY_LIST} ${Boost_LIBRARIES})