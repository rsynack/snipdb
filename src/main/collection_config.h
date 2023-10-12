#pragma once

#include "key.h"
#include "key_tool.h"

#include <string>

namespace snipdb
{
    class ICollection;
    class CollectionConfig
    {
    public:
        IKey key;
        std::string name;
        std::string dbName;

    public:
        const bool isKeyIncrement() const;
        const std::string getId() const;
        const KeyTool *getKeyTool(const ICollection *collection) const;
    };
}