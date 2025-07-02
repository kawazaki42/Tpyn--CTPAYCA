cmake_minimum_required(VERSION 3.10)
project(SinglyLinkedListExample)

add_executable(list_single main.c)
target_link_libraries(list_single PUBLIC sllist)
target_include_directories(list_single PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/../mylibs/"
                          )
# include_directories(
#                           "${PROJECT_BINARY_DIR}"
#                           "${PROJECT_SOURCE_DIR}/../mylibs/"
#                           )