#pragma once

#include "Logger.h"
#include "MovieMetaDataRepository.h"
#include <memory>
#include <string>
#include <vector>

class MovieData;

typedef std::vector<std::shared_ptr<MovieData>> Movies;

class MetaDataProcessor
{
    MovieMetaDataRepository& m_repository;
    std::shared_ptr<LoggerFactory> m_loggerFactory;

public:
    MetaDataProcessor(MovieMetaDataRepository& respository);

    MetaDataProcessor(MovieMetaDataRepository& respository, std::shared_ptr<LoggerFactory> m_loggerFactory);

    ~MetaDataProcessor();

    void ProcessMovies(const std::vector<std::string>& movieNames, Movies& result);
};