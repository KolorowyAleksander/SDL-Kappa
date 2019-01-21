cmake_minimum_required(VERSION 3.10)

project(kappa)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_DIRS})

add_executable(kappa main.cpp)
target_link_libraries(kappa ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
