if (ENABLE_TESTING)
    #For Microsoft Compiler
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    file(GLOB tests_src
            *.cpp
            )

    add_executable(
            MovieDataFetcherTests
            ${tests_src}
    )

    target_link_libraries(MovieDataFetcherTests PRIVATE
            GTest::gtest
            GTest::gmock
            MovieDataFetcher
            )

    include(GoogleTest)
    #    gtest_discover_tests(MovieDataFetcherTests)
endif ()
