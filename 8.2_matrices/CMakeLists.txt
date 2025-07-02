cmake_minimum_required(VERSION 3.10)
project(MatricesExample2)
add_executable(matrix2 main.c ../libarrays/arrays.c)
target_include_directories(matrix2 PUBLIC ../libarrays)