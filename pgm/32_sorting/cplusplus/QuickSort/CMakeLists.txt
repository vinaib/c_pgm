cmake_minimum_required(VERSION 3.16)

set(CXX_STANDARD_REQUIRED 14)

project(quickSort)

add_executable(${PROJECT_NAME} app.cpp ../common/common.cpp quickSort.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ../common)
