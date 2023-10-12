#include "collection.h"

using namespace snipdb;

const CollectionConfig &ICollection::getConfig() const
{
    return this->config;
}

IKey Collection::insert(std::string json)
{
    const CollectionConfig &config = this->getConfig();
    const KeyTool *keyTool = config.getKeyTool(this);
    IKey key = keyTool->nextKey();

    this->collectionFileSet.insert(key, json);

    return key;
}

void Collection::update(std::string json)
{
}

void Collection::remove(IKey key)
{
}

std::optional<std::string> Collection::find(IKey key)
{
    std::optional<std::string> value;
    return value;
}

const KeyFile *Collection::_getKeyFile() const
{
    return this->collectionFileSet._getKeyFile();
}