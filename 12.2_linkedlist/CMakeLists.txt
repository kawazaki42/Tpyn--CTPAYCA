cmake_minimum_required(VERSION 3.10)
project(DoublyLinkedListExample)

add_executable(list_double main.c)
target_link_libraries(list_double PUBLIC dllist)
target_include_directories(list_double PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/../mylibs/"
                          )
# include_directories(
#                           "${PROJECT_BINARY_DIR}"
#                           "${PROJECT_SOURCE_DIR}/../mylibs/"
#                           )