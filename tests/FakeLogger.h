#pragma once

#include "Logger.h"
#include "gmock/gmock.h"

class FakeLogger : public Logger
{
public:
    MOCK_METHOD1(LogError, void(std::string));
};