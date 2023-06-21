# Проверяем версию CMake
cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)

include("${CMAKE_CURRENT_SOURCE_DIR}/submodules/sway.module_core/cmakehelpers/custom_enable_cxx17.cmake")
include("${CMAKE_CURRENT_SOURCE_DIR}/submodules/sway.module_core/cmakehelpers/custom_add_subdirectory.cmake")

# Мета-информация о проекте
set(META_MATH_PRJNAME "module_math")
set(META_MATH_LIBNAME "lib${META_MATH_PRJNAME}")
set(META_MATH_VERSION_MAJOR 0)
set(META_MATH_VERSION_MINOR 3)
set(META_MATH_VERSION_PATCH 16)
set(META_MATH_VERSION ${META_MATH_VERSION_MAJOR}.${META_MATH_VERSION_MINOR}.${META_MATH_VERSION_PATCH})

# Опции сборки
option(MODULE_MATH_ENABLE_COVERAGE "Enable coverage builds" OFF)
option(MODULE_MATH_ENABLE_TESTS "Enable test builds" OFF)
option(CUSTOM_GTEST_ROOT_DIR "GTest root directory" OFF)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build" FORCE)
endif ()

project(${META_MATH_PRJNAME} VERSION ${META_MATH_VERSION} LANGUAGES CXX)

if (MODULE_MATH_ENABLE_COVERAGE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftest-coverage")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif ()

# Определяем каталог вывода по умолчанию
if (CMAKE_BUILD_TYPE MATCHES Debug)
  set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/dbg")
  set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/dbg")
else ()
  set(LIBRARY_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")
  set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")
endif ()

set(MODULE_MATH_DIR ${CMAKE_CURRENT_LIST_DIR})

# Добавляем пути для поиска хедеров
# include_directories("${CUSTOM_THIRDPARTY_DIR}/glm")
include_directories("${MODULE_MATH_DIR}/submodules/sway.module_core/lib/include")
include_directories("${MODULE_MATH_DIR}/lib/include")

# Добавляем построение тестов
if (MODULE_MATH_ENABLE_TESTS)
  if (MODULE_MATH_SHARED_LIB)
    message(STATUS "[${META_MATH_PRJNAME}]: Tests are only allowed with a static lib")
  else ()
    message(STATUS "[${META_MATH_PRJNAME}]:Tests have been enabled")
    add_subdirectory(lib/tests/google)
  endif ()
endif ()
