#pragma once

#include "collection_config.h"
#include "file.h"

#include <string>

namespace snipdb
{
    class DeleteFile : public File
    {
    public:
        DeleteFile(const CollectionConfig &config) : File(config)
        {
        }

    protected:
        const std::string getName() const
        {
            return "";
        }

        const std::string getPostfix() const
        {
            return "del";
        }
    };
}