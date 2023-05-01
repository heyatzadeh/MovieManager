#pragma once

#include "Logger.h"
#include "gmock/gmock.h"

class FakeLoggerFactory : public LoggerFactory
{
public:
    MOCK_METHOD0(CreateLogger, std::shared_ptr<Logger>());
};
