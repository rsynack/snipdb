#include "collection_config.h"

using namespace snipdb;

const bool CollectionConfig::isKeyIncrement() const
{
    return this->key.type == KeyType::Number;
}

const std::string CollectionConfig::getId() const
{
    return this->dbName + "/" + this->name;
}