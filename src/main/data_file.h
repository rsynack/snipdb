#pragma once

#include "file.h"
#include "collection_config.h"

#include <string>

namespace snipdb
{
    class DataFile : public File
    {
    public:
        DataFile(const CollectionConfig &config) : File(config)
        {
        }

    protected:
        const std::string getName() const
        {
            return "";
        }

        const std::string getPostfix() const
        {
            return "dat";
        }
    };
}