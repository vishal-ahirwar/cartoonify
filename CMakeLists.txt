cmake_minimum_required(VERSION 3.1)
project(cartoonify)
find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS} ./src)

add_executable(main ./src/main.cpp ./src/cartoon.cpp)
target_link_libraries(main ${OpenCV_LIBS})