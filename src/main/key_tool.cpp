#include "key_tool.h"
#include "key_file.h"

using namespace snipdb;

NumberKeyTool::NumberKeyTool(const KeyFile *keyFile)
{
    KeyFile file(*keyFile);
    this->keyFile = std::make_shared<KeyFile>(file);
}

IKey NumberKeyTool::nextKey() const
{
    LongKey key;
    key.value = 42;
    return key;
}

IKey GuidKeyTool::nextKey() const
{
    GuidKey key;
    key.value = "asdsd";

    return key;
}