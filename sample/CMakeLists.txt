# project name
project(sample)

# executable files
add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/core
        ${CMAKE_SOURCE_DIR}/sample
        )

target_link_libraries(${PROJECT_NAME} PRIVATE
        sting::dev
        )