#pragma once

#include "key.h"

#include "index_file.h"
#include "key_file.h"
#include "delete_file.h"
#include "data_file.h"
#include "collection_config.h"

#include <string>
#include <optional>
#include <memory>

namespace snipdb
{
    class CollectionFileSet
    {
    private:
        const CollectionConfig &config;

        IndexFile indexFile;
        DeleteFile deleteFile;
        DataFile dataFile;

        std::shared_ptr<KeyFile> keyFile;

    public:
        CollectionFileSet(const CollectionConfig &config) : config(config),
                                                            indexFile(IndexFile(config)),
                                                            deleteFile(DeleteFile(config)),
                                                            dataFile(DataFile(config))
        {
            this->initialize();
        }

        void initialize();

        IKey insert(std::string json);
        void remove(IKey key);

    private:
        void loadIndex();
        void loadData();
        void loadDelete();
        void loadKey();
    };
}