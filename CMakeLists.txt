#---------------------------------------------------------------------------------
# CMake version
#---------------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

#---------------------------------------------------------------------------------
# Project directories
#---------------------------------------------------------------------------------

set(MODULE_MATH_LIST_DIR "${CMAKE_CURRENT_LIST_DIR}")
set(MODULE_MATH_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(MODULE_MATH_CMAKE_DIR "${MODULE_MATH_ROOT_DIR}/submodules/sway.module_core/cmake_modules")
set(MODULE_MATH_BIN_DIR "${MODULE_MATH_ROOT_DIR}/bin")

#---------------------------------------------------------------------------------
# Include CMake modules
#---------------------------------------------------------------------------------

include("${MODULE_MATH_CMAKE_DIR}/options.cmake")
include("${MODULE_MATH_CMAKE_DIR}/set_output_dir.cmake")
include("${MODULE_MATH_CMAKE_DIR}/project_metadata.cmake")
include("${MODULE_MATH_CMAKE_DIR}/modules/create_object_library.cmake")
include("${MODULE_MATH_CMAKE_DIR}/enable_cxx17.cmake")

#---------------------------------------------------------------------------------
# Build options
#---------------------------------------------------------------------------------

option(MODULE_MATH_ENABLE_COVERAGE "Enable coverage builds" OFF)
option(MODULE_MATH_ENABLE_TESTS "Enable test builds" OFF)

#---------------------------------------------------------------------------------
# Project
#---------------------------------------------------------------------------------

project_metadata("math" 0.5.2)
project(${MODULE_MATH_PROJ_NAME} VERSION ${MODULE_MATH_VERSION} LANGUAGES CXX)

#---------------------------------------------------------------------------------
# Coverage
#---------------------------------------------------------------------------------

if(MODULE_MATH_ENABLE_COVERAGE)
  enable_coverage()
endif()

#---------------------------------------------------------------------------------
# Executable output path
#---------------------------------------------------------------------------------

set_output_dir("${CMAKE_SOURCE_DIR}/bin")

#---------------------------------------------------------------------------------
# Tests
#---------------------------------------------------------------------------------

if(MODULE_MATH_ENABLE_TESTS)
  if(${MODULE_MATH_LIB_TYPE} MATCHES "static")
    message(STATUS "[${MODULE_MATH_PROJ_NAME}]: Tests have been enabled")
    add_subdirectory(lib/cxx/tests/google)
  else()
    message(FATAL_ERROR "[${MODULE_MATH_PROJ_NAME}]: Tests are only allowed with a static lib")
  endif()
endif()
