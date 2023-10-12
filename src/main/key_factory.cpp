#include "key_factory.h"
#include "collection.h"

using namespace snipdb;

const KeyTool *KeyFactory::createKeyTool(const ICollection *collection)
{
    const CollectionConfig &config = collection->getConfig();

    if (this->keyToolCache.find(config.getId()) == this->keyToolCache.end())
    {
        if (config.isKeyIncrement())
        {
            NumberKeyTool keyTool(collection->_getKeyFile());
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