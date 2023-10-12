#pragma once

#include <string>

namespace snipdb
{
    class Configuration
    {
    private:
        std::string dbName;

    public:
        Configuration(std::string dbName)
        {
            this->dbName = dbName;
        }

        const std::string getPath() const
        {
            return "./data";
        }

        static Configuration getConfig(std::string dbName)
        {
            static Configuration instance(dbName);
            return instance;
        }
    };
}