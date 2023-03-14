SET(LIB_NAME StateController)

SET(SRC StateMachine.cpp StateNode.cpp EventManager.cpp)

include_directories("includes")

add_library(${LIB_NAME}_lib ${SRC})


target_include_directories(${LIB_NAME}_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")


