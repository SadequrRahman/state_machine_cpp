cmake_minimum_required(VERSION 3.00.0)


project(Controller)

SET(SRC main.cpp)

include_directories("./StateController/includes")
include_directories("./States/includes")

add_subdirectory("StateController")
add_subdirectory("States")

add_executable(${CMAKE_PROJECT_NAME}_exe ${SRC})

target_link_libraries(${CMAKE_PROJECT_NAME}_exe PUBLIC StateController_lib)
target_link_libraries(${CMAKE_PROJECT_NAME}_exe PUBLIC States_lib)