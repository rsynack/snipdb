#include "collection_file_set.h"
#include "key_factory.h"

using namespace snipdb;

void CollectionFileSet::initialize()
{
    if (config.isKeyIncrement())
    {
        KeyFile keyFile(config);
        this->keyFile = std::make_shared<KeyFile>(keyFile);
    }
}

IKey CollectionFileSet::insert(std::string json)
{
    // TODO 1. insert in data file, 2. insert in index file

    const KeyTool *keyTool = KeyFactory::getKeyTool(config, keyFile.get());
    IKey key = keyTool->nextKey();

    return key;
}