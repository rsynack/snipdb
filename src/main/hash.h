#pragma once

#include <string>

namespace snipdb
{
    class Hash
    {

    public:
        static const std::string createHash(std::string value, size_t size)
        {
            static const char token[] = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

            // TODO Hash

            return value;
        }
    };
}