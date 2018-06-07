# Проверяем версию CMake
cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

# Устанавливаем имя проекта
set(MODULE_MATH_PROJECT_NAME module_math)
project(${MODULE_MATH_PROJECT_NAME} CXX)

option(BUILD_TESTS "Build unit tests" OFF)
# set(BUILD_TESTS OFF CACHE INTERNAL "" FORCE)

set(MODULE_MATH_VERSION_MAJOR 1)
set(MODULE_MATH_VERSION_MINOR 0)

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/modules/sway.module_core/include")

set(CMAKE_CXX_FLAGS "-Wall -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
add_definitions(-std=c++14)

if(BUILD_TESTS)
	add_subdirectory(tests)
endif()
