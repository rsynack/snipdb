#include "collection.h"

using namespace snipdb;

const CollectionConfig &ICollection::getConfig() const
{
    return this->config;
}

IKey Collection::insert(std::string json)
{
    return this->collectionFileSet.insert(json);
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