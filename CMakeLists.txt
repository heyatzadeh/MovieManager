cmake_minimum_required(VERSION 3.16)

project(MovieManager VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake/")
include(AddGitSubmodule)
include(FetchContent)

add_git_submodule(3rdParty/curl)
add_git_submodule(3rdParty/googletest)


FETCHCONTENT_DECLARE(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt
        GIT_TAG 9.1.0
)
FETCHCONTENT_MAKEAVAILABLE(fmt)
#FETCHCONTENT_DECLARE(
#        spdlog
#        GIT_REPOSITORY https://github.com/gabime/spdlog
#        GIT_TAG 1.11.0
#)
#FETCHCONTENT_MAKEAVAILABLE(spdlog)

add_subdirectory(3rdParty)

#add_subdirectory(3rdParty/googletest)
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#link_directories(
#        3rdParty/Bin
#)
#
#include_directories(
#        3rdParty/Include
#)


file(GLOB movie_data_fetcher_src
        MovieDataFetcher/*.h
        MovieDataFetcher/*.cpp
        )

add_library(
        MovieDataFetcher
        STATIC
        ${movie_data_fetcher_src}
)

target_link_libraries(MovieDataFetcher PUBLIC
        optimized libcurl
        debug libcurl
        )

#file(GLOB tests_src
#        MovieDataFetcherTests/*.h
#        MovieDataFetcherTests/*.cpp
#        )
#enable_testing()

#add_executable(
#        MovieDataFetcherTests
#        ${tests_src}
#)
#target_link_libraries(
#        MovieDataFetcherTests
#        GTest::gtest_main
#        GTest::gmock
#        MovieDataFetcher
#)
#target_include_directories(
#        MovieDataFetcherTests
#        PRIVATE
#        MovieDataFetcher
#)

#include(GoogleTest)
#gtest_discover_tests(MovieDataFetcherTests)

file(GLOB movie_data_fetcher_runner_src
        MovieDataFetcherRunner/*.h
        MovieDataFetcherRunner/*.cpp
        )
add_executable(
        MovieDataFetcherRunner
        ${movie_data_fetcher_runner_src}
)
target_link_libraries(MovieDataFetcherRunner PUBLIC
        MovieDataFetcher
        fmt::fmt
        )