# cmake minimum version requirements
cmake_minimum_required(VERSION 3.10)

# project name
project(sting_dev)

# include all source files
file(GLOB SOURCE_FILES
        logger/logger.cpp
        utility/utility.cpp
        asio/server.cpp
        asio/client.cpp
        )
# use static boost libraries
set(Boost_USE_STATIC_LIBS ON)

# find boost
find_package(Boost REQUIRED COMPONENTS
        program_options
        unit_test_framework
        log
        log_setup
        chrono
        system
        thread
        )

# include list
set(INCLUDE_LIST ${CMAKE_CURRENT_SOURCE_DIR})

# library list
#set(LIBRARY_LIST
#        # std library
#        pthread
#        )

# create a static library
add_library(sting_dev STATIC ${SOURCE_FILES})

# include libraries
target_include_directories(sting_dev PUBLIC ${INCLUDE_LIST} ${Boost_INCLUDE_DIRS})

# link libraries
target_link_libraries(sting_dev PUBLIC ${LIBRARY_LIST} ${Boost_LIBRARIES})
