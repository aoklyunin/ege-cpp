cmake_minimum_required(VERSION 3.21)
project(ege_cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(example_1_1 problem1/example_1.cpp)
add_executable(example_1_1_optimized problem1/example_1_optimized.cpp)
add_executable(example_1_2_dijkstra  problem1/example_2_dijkstra.cpp)
add_executable(example_1_2 problem1/example_2.cpp)
add_executable(example_1_3 problem1/example_3.cpp)
add_executable(example_1_4 problem1/example_4.cpp)
add_executable(example_1_5 problem1/example_5.cpp)
add_executable(example_1_6 problem1/example_6.cpp)
add_executable(example_1_7 problem1/example_7.cpp)
add_executable(example_1_8 problem1/example_8.cpp)
add_executable(example_1_9 problem1/example_9.cpp)

add_executable(example_2_1 problem2/example_1.cpp)
add_executable(example_2_2 problem2/example_2.cpp)
add_executable(example_2_3 problem2/example_3.cpp)
add_executable(example_2_4 problem2/example_4.cpp)
add_executable(example_2_5 problem2/example_5.cpp)



add_executable(example_5_1 problem5/example_1.cpp)
add_executable(example_5_2 problem5/example_2.cpp)
add_executable(example_5_3 problem5/example_3.cpp)
add_executable(example_5_4 problem5/example_4.cpp)
add_executable(example_5_5 problem5/example_5.cpp)
add_executable(example_5_6 problem5/example_6.cpp)
add_executable(example_5_7 problem5/example_7.cpp)


add_executable(example_6_1 problem6/example_1.cpp)
add_executable(example_6_1_task problem6/tasks/example_1.cpp)
add_executable(example_6_2 problem6/example_2.cpp)
add_executable(example_6_2_task problem6/tasks/example_2.cpp)


add_executable(example_8_1 problem8/example_1.cpp)
add_executable(example_8_2 problem8/example_2.cpp)
add_executable(example_8_3 problem8/example_3.cpp)
add_executable(example_8_4 problem8/example_4.cpp)

add_executable(example_12_1 problem12/example_1.cpp)
add_executable(example_12_2 problem12/example_2.cpp)

add_executable(example_14_1 problem14/example_1.cpp)
add_executable(example_14_2 problem14/example_2.cpp)
add_executable(example_14_3 problem14/example_3.cpp)