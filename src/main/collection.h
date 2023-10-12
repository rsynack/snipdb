#pragma once

#include "collection_config.h"
#include "key.h"
#include "key_factory.h"
#include "collection_file_set.h"

#include <string>
#include <map>
#include <optional>

namespace snipdb
{
    class ICollection
    {
    private:
        CollectionConfig config;

    public:
        ICollection(CollectionConfig config) : config(config) {}

        const CollectionConfig &getConfig() const;

        virtual const KeyFile *_getKeyFile() const = 0;
    };

    class Collection : public ICollection
    {
    private:
        CollectionFileSet collectionFileSet;

    public:
        Collection() = delete;
        Collection(CollectionConfig config) : ICollection(config), collectionFileSet(CollectionFileSet(config)) {}
        ~Collection() {}

        IKey insert(std::string json);
        void update(std::string json);
        void remove(IKey key);

        std::optional<std::string> find(IKey key);

        const KeyFile *_getKeyFile() const;

    protected:
        void insert(IKey key, std::string json);
    };
}