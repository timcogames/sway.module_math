# Проверяем версию CMake
cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)

# Устанавливаем имя проекта
set(MODULE_MATH_PROJECT_NAME module_math)
project(${MODULE_MATH_PROJECT_NAME} C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Флаги сборки
option(ENABLE_EXAMPLES "Enable example builds" OFF)
option(ENABLE_TESTS "Enable test builds" OFF)

# Устанавливаем версию библиотеки
set(MODULE_MATH_VERSION_MAJOR 0)
set(MODULE_MATH_VERSION_MINOR 1)
set(MODULE_MATH_VERSION_PATCH 0)
set(MODULE_MATH_VERSION_STRING ${MODULE_MATH_VERSION_MAJOR}.${MODULE_MATH_VERSION_MINOR}.${MODULE_MATH_VERSION_PATCH})

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/modules/sway.module_core/include")

# Добавляем построение тестов
if(ENABLE_TESTS)
	message(STATUS "Tests have been enabled")
	add_subdirectory(tests)
endif()
