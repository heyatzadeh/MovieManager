add_executable(MovieDataFetcherRunner
        main.cpp
)

target_link_libraries(MovieDataFetcherRunner PRIVATE
        MovieDataFetcher
)