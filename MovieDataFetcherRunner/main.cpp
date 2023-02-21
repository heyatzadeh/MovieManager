#include <iostream>

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
    processor.ProcessMovies({"Batman Begins"}, result);

    for (auto movie : result)
    {
        std::cout << "Title: " << movie->GetTitle() << std::endl;
        std::cout << "IMDB Id: " << movie->GetImdbId() << std::endl << std::endl;
        std::cout << movie->GetPlot() << std::endl << std::endl;
        std::cout << "Length (min.) " << movie->GetLengthMin() << std::endl << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    return 0;
}
