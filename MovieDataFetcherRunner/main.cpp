#include <iostream>
#include <fmt/format.h>

#include "../MovieDataFetcher/MetaDataProcessor.h"
#include "../MovieDataFetcher/RestApiClient.h"
#include "../MovieDataFetcher/TheMovieDbDataFactory.h"
#include "../MovieDataFetcher/TheMovieDbRepository.h"
#include "../MovieDataFetcherTests/ApiKey.h"

int main()
{
    TheMovieDbDataFactory dataFactory;
    RestApiClient client;
    TheMovieDbRepository repository(MY_API_KEY, dataFactory, client);
    MetaDataProcessor processor(repository);

    Movies result;
    processor.ProcessMovies({"Batman Begins", "Spider-man"}, result);

    for (const auto& movie : result)
    {
        auto output = fmt::format("Title: {}\nIMDB Id: {}\n\n{}\n\nLength (min.) {}\n\n",
                                  movie->GetTitle(),movie->GetImdbId(),movie->GetPlot(),movie->GetLengthMin());
        std::cout << output;
        std::cout << "----------------------------------------" << std::endl;
    }

    return 0;
}
