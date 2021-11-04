# project name
project(sample)

# executable files
add_executable(sample main.cpp)

target_include_directories(sample PUBLIC
        ${CMAKE_SOURCE_DIR}/core
        ${CMAKE_SOURCE_DIR}/sample
        )

target_link_libraries(${PROJECT_NAME} PRIVATE devkits)