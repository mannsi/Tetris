cmake_minimum_required(VERSION 2.8.4)
project(Tetris)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp OpenGlUi.cpp BoxShape.h Blocks/Block.cpp Point.h BlockForm.cpp  Tetris.cpp)
set(BLOCK_FILES Blocks/LongBlock.cpp Blocks/BoxBlock.cpp Blocks/TBlock.cpp Blocks/SBlock.cpp Blocks/ZBlock.cpp Blocks/LBlock.cpp Blocks/JBlock.cpp)
add_executable(Tetris ${SOURCE_FILES} ${BLOCK_FILES})

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)
include_directories(. Blocks ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
target_link_libraries(Tetris ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES})

add_subdirectory(Test)
