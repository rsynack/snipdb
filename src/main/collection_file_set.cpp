#include "collection_file_set.h"

using namespace snipdb;

void CollectionFileSet::initialize()
{
    if (config.isKeyIncrement())
    {
        KeyFile keyFile(config);
        this->keyFile = std::make_shared<KeyFile>(keyFile);
    }
}

void CollectionFileSet::insert(IKey key, std::string json)
{
}