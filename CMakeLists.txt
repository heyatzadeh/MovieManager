cmake_minimum_required(VERSION 3.14)

project(MovieManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

link_directories(
    3rdParty/Bin
)

include_directories(
    3rdParty/Include
)

file(GLOB movie_data_fetcher_src
#    MovieDataFetcher/*.h
    MovieDataFetcher/*.cpp
)
add_library(
    MovieDataFetcher
    STATIC
    ${movie_data_fetcher_src}
)
target_link_libraries(
    MovieDataFetcher

    optimized libcurl
    debug libcurl-d
)

file(GLOB tests_src
#    MovieDataFetcherTests/*.h
    MovieDataFetcherTests/*.cpp
)
enable_testing()

add_executable(
  MovieDataFetcherTests
  ${tests_src}
)
target_link_libraries(
  MovieDataFetcherTests
  GTest::gtest_main
  GTest::gmock
  MovieDataFetcher
)
target_include_directories(
    MovieDataFetcherTests
    PRIVATE
    MovieDataFetcher
)

include(GoogleTest)
#gtest_discover_tests(MovieDataFetcherTests)

file(GLOB movie_data_fetcher_runner_src
#    MovieDataFetcherRunner/*.h
    MovieDataFetcherRunner/*.cpp
)
add_executable(
    MovieDataFetcherRunner
    ${movie_data_fetcher_runner_src}
)
target_link_libraries(
    MovieDataFetcherRunner
    MovieDataFetcher
)

install(TARGETS MovieDataFetcherRunner
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
