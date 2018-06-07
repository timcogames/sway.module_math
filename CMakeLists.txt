# Проверяем версию CMake
cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

# Устанавливаем имя проекта
set(MODULE_MATH_PROJECT_NAME module_math)
project(${MODULE_MATH_PROJECT_NAME} CXX)

option(BUILD_TESTS "Build unit tests" OFF)

# Устанавливаем версию библиотеки
set(MODULE_MATH_VERSION_MAJOR 0)
set(MODULE_MATH_VERSION_MINOR 1)
set(MODULE_MATH_VERSION_PATCH 0)
set(MODULE_MATH_VERSION_STRING ${MODULE_MATH_VERSION_MAJOR}.${MODULE_MATH_VERSION_MINOR}.${MODULE_MATH_VERSION_PATCH})

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/modules/sway.module_core/include")

if(BUILD_TESTS)
	add_subdirectory(tests)
endif()
