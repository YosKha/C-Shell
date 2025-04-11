cmake_minimum_required(VERSION 3.30)
project(Shell C)

set(CMAKE_C_STANDARD 11)

add_executable(Shell src/main/main.c src/main/command.c)
