# Мета-информация о проекте
set(META_PROJECT_NAME_TESTS module_math_tests)
set(META_LIB_NAME_TESTS lib${META_PROJECT_NAME_TESTS})

project(${META_PROJECT_NAME_TESTS} C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(Boost_USE_STATIC_LIBS ON)
set(BOOST_COMPONENTS unit_test_framework)
find_package(Boost 1.58 REQUIRED COMPONENTS ${BOOST_COMPONENTS})
if(NOT Boost_FOUND)
	message(FATAL_ERROR "Fatal error: Boost (version >= 1.58) required.")
else()
	message(STATUS "Boost includes: ${Boost_INCLUDE_DIRS}")
	message(STATUS "Boost libs: ${Boost_LIBRARIES}")

	include_directories(${Boost_INCLUDE_DIRS})
endif()

# Добавляем пути для поиска хедеров
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/modules/sway.module_core/include")

# Получаем пути ко всем исходникам с тестами
file(GLOB MODULE_MATH_SOURCE_TESTS ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(${META_LIB_NAME_TESTS} ${MODULE_MATH_SOURCE_TESTS})

target_include_directories(${META_LIB_NAME_TESTS} PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(${META_LIB_NAME_TESTS} ${Boost_LIBRARIES})

add_custom_command(TARGET ${META_LIB_NAME_TESTS} POST_BUILD COMMAND ${META_LIB_NAME_TESTS})
