#include "collection_config.h"
#include "key_factory.h"

using namespace snipdb;

const bool CollectionConfig::isKeyIncrement() const
{
    return this->key.type == KeyType::Number;
}

const std::string CollectionConfig::getId() const
{
    return this->dbName + "/" + this->name;
}

const KeyTool *CollectionConfig::getKeyTool(const ICollection *collection) const
{
    return KeyFactory::getKeyTool(collection);
}