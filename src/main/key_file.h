#pragma once

#include "key.h"
#include "file.h"
#include "collection_config.h"

#include <string>

namespace snipdb
{
    class KeyFile : public File
    {
    public:
        KeyFile(const CollectionConfig &config) : File(config)
        {
        }

        LongKey getKey();

    protected:
        const std::string getName() const
        {
            return "";
        }

        const std::string getPostfix() const
        {
            return "key";
        }
    };
}