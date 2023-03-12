SET(LIB_NAME States)

SET(SRC PowerOnResetState.cpp TestState.cpp)

include_directories("includes")
include_directories("../StateController/includes")

add_library(${LIB_NAME}_lib ${SRC})


target_include_directories(${LIB_NAME}_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")


