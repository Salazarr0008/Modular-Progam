cmake_minimum_required(VERSION 3.20) 
PROJECT(gradebook LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(gradebook_lib src/utilities.cpp src/printing.cpp src/grading.cpp)
target_include_directories(gradebook_lib PUBLIC includes)

add_executable(gradebook src/main.cpp)
target_link_libraries(gradebook PRIVATE gradebook_lib)
