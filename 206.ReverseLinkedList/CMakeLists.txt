cmake_minimum_required(VERSION 3.23)

add_compile_options("-Wall")
add_compile_options("-Werror")
add_compile_options("-Wextra")

project(206.ReverseLinkedList C)

set(CMAKE_C_STANDARD 23)

add_executable(206.ReverseLinkedList main.c)
