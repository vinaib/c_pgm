cmake_minimum_required(VERSION 3.16)

set(CXX_STANDARD_REQUIRED 14)

project(countSort)

add_executable(${PROJECT_NAME} countSort.cpp ../common/common.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ../common)
