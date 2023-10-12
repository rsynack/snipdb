#include "key_factory.h"
#include "collection.h"

using namespace snipdb;

const KeyTool *KeyFactory::createKeyTool(const CollectionConfig &config, const KeyFile *keyFile)
{
    if (this->keyToolCache.find(config.getId()) == this->keyToolCache.end())
    {
        if (config.isKeyIncrement())
        {
            NumberKeyTool keyTool(keyFile);
            std::shared_ptr<KeyTool> ptr = std::make_shared<NumberKeyTool>(keyTool);
            this->keyToolCache.emplace(std::make_pair(config.getId(), ptr));
        }
        else
        {
            GuidKeyTool keyTool;
            std::shared_ptr<KeyTool> ptr = std::make_shared<GuidKeyTool>(keyTool);
            this->keyToolCache.emplace(std::make_pair(config.getId(), ptr));
        }

        // TODO error or default?
    }

    return this->keyToolCache.at(config.getId()).get();
}