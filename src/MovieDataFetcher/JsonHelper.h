#pragma once

#include "rapidjson/document.h"
#include <string>

class JsonHelper
{
public:
    JsonHelper();

    ~JsonHelper();

    static std::string GetMatchingTitleIdFromMovieList(const std::string& title, const std::string& jsonString);

private:
    static const rapidjson::Value&
    FindMovieByTitle(const std::string& title, rapidjson::GenericValue<rapidjson::UTF8<>>::Array results);
};
