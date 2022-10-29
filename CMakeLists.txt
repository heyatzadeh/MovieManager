cmake_minimum_required(VERSION 3.14)

project(MovieManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(MovieManager main.cpp)

install(TARGETS MovieManager
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

enable_testing()

add_executable(
  hello_test
  hello_test.cpp
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)
