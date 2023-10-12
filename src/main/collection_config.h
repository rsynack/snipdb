#pragma once

#include "key.h"

#include <string>

namespace snipdb
{
    class CollectionConfig
    {
    public:
        IKey key;
        std::string name;
        std::string dbName;

    public:
        const bool isKeyIncrement() const;
        const std::string getId() const;
    };
}