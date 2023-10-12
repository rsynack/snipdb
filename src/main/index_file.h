#pragma once

#include "file.h"
#include "collection_config.h"

#include <string>

namespace snipdb
{
    struct Value
    {
        int64_t position;
        int64_t size;
    };

    class IndexFile : public File
    {
    public:
        IndexFile(const CollectionConfig &config) : File(config)
        {
        }

        void add(IKey key, Value value);
        Value get(IKey key);
        void remove(IKey key);

    protected:
        const std::string getName() const
        {
            return "";
        }

        const std::string getPostfix() const
        {
            return "idx";
        }
    };
}