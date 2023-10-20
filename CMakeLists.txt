#_________________________________________________________________________________
#                                                                    CMake version
cmake_minimum_required(VERSION 3.14.3 FATAL_ERROR)

#_________________________________________________________________________________
#                                                              Project directories
set(MODULE_MATH_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(MODULE_MATH_CMAKE_DIR ${MODULE_MATH_ROOT_DIR}/submodules/sway.module_core/cmakehelpers)
set(MODULE_MATH_BIN_DIR ${MODULE_MATH_ROOT_DIR}/bin)

#_________________________________________________________________________________
#                                                            Include CMake modules
include("${MODULE_MATH_CMAKE_DIR}/options.cmake")
include("${MODULE_MATH_CMAKE_DIR}/set_output_dir.cmake")
include("${MODULE_MATH_CMAKE_DIR}/project_metadata.cmake")
include("${MODULE_MATH_CMAKE_DIR}/enable_cxx17.cmake")

#_________________________________________________________________________________
#                                                                    Build options
option(MODULE_MATH_ENABLE_COVERAGE "Enable coverage builds" OFF)
option(MODULE_MATH_ENABLE_TESTS "Enable test builds" OFF)

#_________________________________________________________________________________
#                                                                          Project
project_metadata("math" 0.5.2)
project(${MODULE_MATH_TARGET} VERSION ${MODULE_MATH_VERSION} LANGUAGES CXX)

#_________________________________________________________________________________
#                                                                         Coverage
if(MODULE_MATH_ENABLE_COVERAGE)
  enable_coverage()
endif()

#_________________________________________________________________________________
#                                                           Executable output path
set_output_dir("${CMAKE_SOURCE_DIR}/bin")

#_________________________________________________________________________________
#                                                          Include project headers
include_directories("${CMAKE_CURRENT_LIST_DIR}/submodules/sway.module_core/lib/cpp/include")
include_directories("${CMAKE_CURRENT_LIST_DIR}/lib/cpp/include")

#_________________________________________________________________________________
#                                                                            Tests
if(MODULE_MATH_ENABLE_TESTS)
  if(MODULE_MATH_SHARED_LIB)
    message(STATUS "[${MODULE_MATH_TARGET}]: Tests are only allowed with a static lib")
  else()
    message(STATUS "[${MODULE_MATH_TARGET}]:Tests have been enabled")
    add_subdirectory(lib/cpp/tests/google)
  endif()
endif()
