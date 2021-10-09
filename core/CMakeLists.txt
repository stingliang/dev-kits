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

# include list
set(INCLUDE_LIST
        ${CMAKE_SOURCE_DIR}
        )

# library list
set(LIBRARY_LIST
        # std library
        )

# create a library
add_library(sting_dev STATIC
        ${SOURCE_FILES}
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

if (USE_BOOST)
    find_package(Boost REQUIRED COMPONENTS
            unit_test_framework
            log
            log_setup
            chrono
            system
            thread
            )

    target_include_directories(sting_dev PUBLIC
            ${Boost_INCLUDE_DIRS}
            )

    target_link_libraries(sting_dev ${Boost_LIBRARIES})
endif(USE_BOOST)