#pragma once

#include <string>

class RestApiClient
{
public:
    RestApiClient();

    virtual ~RestApiClient();

    /**
     * @brief performs a get request to the url given
     * @param url
     * @return std::string html response
     */
    virtual std::string HttpGet(std::string& url);
};
