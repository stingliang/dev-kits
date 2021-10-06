# cmake minimum version requirements
cmake_minimum_required(VERSION 3.10)

# project name
project(dev-utility-library)

# use boost or not
option(USE_BOOST "option for boost" ON)
if (USE_BOOST)
    add_definitions(-DUSE_BOOST)
endif(USE_BOOST)

# cmake settings
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/output/lib)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/output/bin)

# print info
set(SPLIT_LINE "-------------------------------------------------------")
message(STATUS ${SPLIT_LINE})
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    message(STATUS "current platform: Linux ")
    message(STATUS "library output path = ${CMAKE_SOURCE_DIR}/output/lib")
    message(STATUS "executable output path = ${CMAKE_SOURCE_DIR}/output/bin")
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "current platform: Windows")
    message(STATUS "LIBRARY_OUTPUT_PATH = ${CMAKE_SOURCE_DIR}/output/lib")
    message(STATUS "EXECUTABLE_OUTPUT_PATH = ${CMAKE_SOURCE_DIR}/output/bin")
else ()
    message(STATUS "other platform: ${CMAKE_SYSTEM_NAME}")
endif (CMAKE_SYSTEM_NAME MATCHES "Linux")
message(STATUS ${SPLIT_LINE})

# cpp version
set(CMAKE_CXX_STANDARD 14)

# library
add_subdirectory(core)

# sample
add_subdirectory(sample)