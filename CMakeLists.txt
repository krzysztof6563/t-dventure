cmake_minimum_required(VERSION 3.0)
project(t-dventure)

file(GLOB t-dventure_SRC
    "*.h"
    "*.cpp"
    "graphics/*.h"
    "graphics/*.cpp"
    "input/*.h"
    "input/*.cpp"
)

set (CMAKE_CXX_FLAGS "-std=c++17 ")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${t-dventure_SRC})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})