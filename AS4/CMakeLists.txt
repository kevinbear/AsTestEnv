cmake_minimum_required(VERSION 3.16.3)
set(CMAKE_CXX_STANDARD 11)
project(A04)
include_directories(${PROJECT_SOURCE_DIR}/include)
# Create a library from library.cpp
add_executable(${PROJECT_NAME} src/unittest.cpp)
# Link the library to the main executable
target_link_libraries(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)