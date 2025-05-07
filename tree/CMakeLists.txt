cmake_minimum_required(VERSION 4.0)
project(tree)
add_library(tree STATIC node.cpp node.h)

target_include_directories(tree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) 
