#pragma once

#include "ErrorRepository.h"
#include <string>

class FileErrorRepository : public ErrorRepository
{
    std::string m_fileName;

public:
    FileErrorRepository(std::string fileName) : m_fileName(fileName)
    {
    }

    void LogBadMovie(std::string movieName) override;
};
;
