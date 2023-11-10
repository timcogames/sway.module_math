# Мета-информация о проекте
set(META_MATH_PRJNAME_TESTS "module_math_tests")
set(META_MATH_EXENAME_TESTS "${META_MATH_PRJNAME_TESTS}")

project(${META_MATH_PRJNAME_TESTS} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(GTest_ROOT "${GLOB_GTEST_ROOT_DIR}")
set(GTEST_INCLUDE_DIR "${GTest_ROOT}/googletest/include")
set(GTEST_LIBRARY_DIR "${GTest_ROOT}/build/lib")

set(GTEST_MAIN_LIBRARY "${GTEST_LIBRARY_DIR}/gtest_main.lib")

# find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

include_directories("${GLOB_THIRD_PARTY_DIR}/glm")
include_directories("${GTEST_INCLUDE_DIR}")

# Получаем пути ко всем исходникам с тестами
file(GLOB MODULE_MATH_SOURCE_TESTS "${PROJECT_SOURCE_DIR}/*.spec.cpp")

add_executable(${META_MATH_EXENAME_TESTS} ${MODULE_MATH_SOURCE_TESTS} "${GTest_ROOT}/googletest/src/gtest_main.cc")
target_link_libraries(${META_MATH_EXENAME_TESTS} ${GTEST_LIBRARY_DIR}/libgtest.a ${CMAKE_DL_LIBS})

add_custom_command(TARGET ${META_MATH_EXENAME_TESTS} POST_BUILD COMMAND ${META_MATH_EXENAME_TESTS})
