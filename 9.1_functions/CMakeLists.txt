cmake_minimum_required(VERSION 3.10)
project(FunctionsExample1)
add_executable(main main.c ../libarrays/arrays.c)
target_include_directories(main PUBLIC ../libarrays)