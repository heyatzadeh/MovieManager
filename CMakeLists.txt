cmake_minimum_required(VERSION 3.16)

project(MovieManager VERSION 1.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_TESTING "Whether to enable unit testing build" ON)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")
include(AddGitSubmodule)
#include(FetchContent)

add_git_submodule(3rdParty/googletest)
add_git_submodule(3rdParty/curl)

#FetchContent_Declare(
#        libcurl
#        GIT_REPOSITORY https://github.com/curl/curl.git
#        GIT_TAG curl-8_0_1
#)
#FetchContent_MakeAvailable(libcurl)

add_subdirectory(configured)
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(app)
