cmake_minimum_required(VERSION 4.0)
project(ecg_tree)
add_executable(ecg_tree ecg_tree.cpp)
target_link_libraries(ecg_tree tree)