cmake_minimum_required(VERSION 2.8.4)
project(Tetris_Tests)

add_subdirectory(gtest-1.7.0)
include_directories("gtest-1.7.0/include")
set(test_source_files BlockTest.cpp test_main.cpp)
set(logic_source_files ../Blocks/Block.cpp ../Blocks/LongBlock.cpp ../BlockForm.cpp ../BoxShape.h ../Color.h ../Blocks/LongBlock.cpp ../Point.h ../Blocks/BoxBlock.cpp ../Blocks/TBlock.cpp)
add_executable(Tetris_Tests ${test_source_files} ${logic_source_files})
target_link_libraries(Tetris_Tests gtest_main)