cmake_minimum_required(VERSION 3.12)
project(FiguresProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif()

find_package(GTest REQUIRED)

add_executable(figures_main main.cpp src/figures.cpp)
target_include_directories(figures_main PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(figures_tests tests/test_figures.cpp src/figures.cpp)
target_include_directories(figures_tests PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(figures_tests GTest::gtest GTest::gtest_main)

enable_testing()
add_test(NAME FiguresTests COMMAND figures_tests)