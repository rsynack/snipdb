#pragma once

#include "key_tool.h"
#include "collection_config.h"
#include "key_file.h"

#include <memory>
#include <map>

namespace snipdb
{
    class KeyFactory
    {
    private:
        std::map<std::string, std::shared_ptr<KeyTool>> keyToolCache;

        const KeyTool *createKeyTool(const CollectionConfig &config, const KeyFile *keyFile);

    public:
        static const KeyTool *getKeyTool(const CollectionConfig &config, const KeyFile *keyFile)
        {
            static KeyFactory factory;
            return factory.createKeyTool(config, keyFile);
        }
    };
}