#include <iostream>

#include "MetaDataProcessor.h"
#include "RestApiClient.h"
#include "TheMovieDbDataFactory.h"
#include "TheMovieDbRepository.h"
#include "config.hpp"

int main()
{
    TheMovieDbDataFactory dataFactory;
    RestApiClient client;
    TheMovieDbRepository repository(MY_API_KEY, dataFactory, client);
    MetaDataProcessor processor(repository);

    std::cout << project_name << '\t' <<  project_version << std::endl;

    Movies result;
    processor.ProcessMovies({"Batman Begins"}, result);

    for (const auto& movie : result)
    {
        std::cout << "Title: " << movie->GetTitle() << std::endl;
        std::cout << "IMDB Id: " << movie->GetImdbId() << std::endl << std::endl;
        std::cout << movie->GetPlot() << std::endl << std::endl;
        std::cout << "Length (min.) " << movie->GetLengthMin() << std::endl << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    return 0;
}
