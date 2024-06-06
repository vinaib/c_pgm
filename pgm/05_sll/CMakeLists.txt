cmake_minimum_required(VERSION 3.16)

set(CXX_STANDARD_REQUIRED 14)

project(SLL)

add_executable(${PROJECT_NAME} src/app.c src/list.c)
target_include_directories(${PROJECT_NAME} PUBLIC ./include)