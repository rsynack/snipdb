#pragma once

#include "collection_config.h"

#include <string>

namespace snipdb
{
    class CollectionConfig;
    class File
    {
    protected:
        const CollectionConfig &config;

    public:
        File(const CollectionConfig &config) : config(config)
        {
        }

    private:
        const std::string getFilename() const
        {
            static const std::string filename = this->getName() + "." + this->getPostfix();
            return filename;
        }

    protected:
        virtual const std::string getName() const = 0;
        virtual const std::string getPostfix() const = 0;
    };
}