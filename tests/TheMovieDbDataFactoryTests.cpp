#include "ErrorParsingMovieDataException.h"
#include "TheMovieDbDataFactory.h"
#include "gtest/gtest.h"

TEST(TheMovieDbDataFactoryTests, CreateFromJson_PassEmptyString_ReturnEmptyClass) {
    TheMovieDbDataFactory factory;

    ASSERT_THROW(factory.CreateFromJson(""), ErrorParsingMovieDataException);
}

TEST(TheMovieDbDataFactoryTests, CreateFromJson_PassValidString_ReturnMovieDetails) {
    std::string input = "{\"id\":284052,\"imdb_id\":\"tt1211837\",\"overview\":\"The movie's plot\",\"title\":\"a movie\",\"runtime\":115}";

    TheMovieDbDataFactory factory;

    auto result = factory.CreateFromJson(input);

    EXPECT_EQ(result->GetImdbId(), "tt1211837");
    EXPECT_EQ(result->GetTitle(), "a movie");
    EXPECT_EQ(result->GetPlot(), "The movie's plot");
    EXPECT_EQ(result->GetLengthMin(), 115);
}
