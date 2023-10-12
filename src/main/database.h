#pragma once

#include "key.h"
#include "collection.h"

#include <string>
#include <map>
#include <memory>

namespace snipdb
{
    class Database
    {
    private:
        const std::string name;
        std::map<std::string, std::shared_ptr<Collection>> collections;

    public:
        Database(const std::string name) : name(name)
        {
        }

        void open();

        Collection createCollection(IKey key, const std::string name)
        {
            Collection collection({
                key : key,
                name : name,
                dbName : this->name
            });

            this->collections.emplace(std::make_pair(name, std::make_shared<Collection>(collection)));

            return collection;
        }

        Collection &getCollection(std::string name)
        {
            return *this->collections.at(name).get();
        }

        void deleteCollection(std::string name);
    };
}