# Проверяем версию CMake
cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)

set(MODULE_MATH_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MODULE_MATH_CMAKE_DIR ${MODULE_MATH_ROOT_DIR}/submodules/sway.module_core/cmakehelpers)
set(MODULE_MATH_BINARY_DIR ${MODULE_MATH_ROOT_DIR}/bin)

include("${MODULE_MATH_CMAKE_DIR}/options.cmake")
include("${MODULE_MATH_CMAKE_DIR}/set_output_dir.cmake")
include("${MODULE_MATH_CMAKE_DIR}/project_metadata.cmake")
include("${MODULE_MATH_CMAKE_DIR}/enable_cxx17.cmake")

project_metadata("math" 0.4.16)

# Опции сборки
option(MODULE_MATH_ENABLE_COVERAGE "Enable coverage builds" OFF)
option(MODULE_MATH_ENABLE_TESTS "Enable test builds" OFF)

# set(GLOB_GTEST_ROOT_DIR ${GLOB_THIRD_PARTY_DIR} CACHE STRING "GTest root directory")
# if (${GLOB_GTEST_ROOT_DIR} STREQUAL "OFF")
# endif ()

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build" FORCE)
endif ()

project(${MODULE_MATH_TARGET} VERSION ${MODULE_MATH_VERSION} LANGUAGES CXX)

if(MODULE_MATH_ENABLE_COVERAGE)
  enable_coverage()
endif()

# Определяем каталог вывода по умолчанию
set_output_dir("${CMAKE_SOURCE_DIR}/bin")

set(MODULE_MATH_DIR ${CMAKE_CURRENT_LIST_DIR})

# Добавляем пути для поиска хедеров
include_directories("${MODULE_MATH_DIR}/submodules/sway.module_core/lib/include")
include_directories("${MODULE_MATH_DIR}/lib/include")

# Добавляем построение тестов
if (MODULE_MATH_ENABLE_TESTS)
  if (MODULE_MATH_SHARED_LIB)
    message(STATUS "[${MODULE_MATH_TARGET}]: Tests are only allowed with a static lib")
  else ()
    message(STATUS "[${MODULE_MATH_TARGET}]:Tests have been enabled")
    add_subdirectory(lib/tests/google)
  endif ()
endif ()
