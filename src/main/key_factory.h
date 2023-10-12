#pragma once

#include "key_tool.h"

#include <memory>
#include <map>

namespace snipdb
{
    class ICollection;
    class KeyFactory
    {
    private:
        std::map<std::string, std::shared_ptr<KeyTool>> keyToolCache;

        const KeyTool *createKeyTool(const ICollection *collection);

    public:
        static const KeyTool *getKeyTool(const ICollection *collection)
        {
            static KeyFactory factory;
            return factory.createKeyTool(collection);
        }
    };
}