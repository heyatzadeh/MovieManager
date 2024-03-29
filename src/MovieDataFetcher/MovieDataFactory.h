#pragma once
#include "MovieData.h"
#include <memory>

class MovieDataFactory
{
public:
    virtual ~MovieDataFactory() = default;

    virtual void GetActors(const std::string& jsonString, std::vector<std::string>& result) const = 0;
    virtual std::shared_ptr<MovieData> CreateFromJson(const std::string& jsonString) const = 0;
};
