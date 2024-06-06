cmake_minimum_required(VERSION 3.16)

set(CXX_STANDARD_REQUIRED 17)

project(24_queue)

add_executable(${PROJECT_NAME} app.c queue.c)
target_include_directories(${PROJECT_NAME} PUBLIC .)
