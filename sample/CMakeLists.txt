# project name
project(sample)

# assign sample generate path
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# executable files
add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}
        )

target_link_libraries(${PROJECT_NAME} PRIVATE
        sting::dev
        )