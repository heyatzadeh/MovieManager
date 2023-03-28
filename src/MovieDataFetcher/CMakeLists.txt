file(GLOB movie_data_fetcher_src
        *.cpp
        )

add_library(MovieDataFetcher STATIC
        ${movie_data_fetcher_src}
        )

target_include_directories(MovieDataFetcher PUBLIC
        "./"
        "../../3rdParty/Include"
        )

target_link_libraries(MovieDataFetcher PRIVATE
        CURL::libcurl
        )