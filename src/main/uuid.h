#pragma once

#include <uuid/uuid.h>

#include <string>

namespace snipdb
{
    class UUID
    {
    public:
        static const std::string createUUID()
        {
            unsigned char *value;
            uuid_generate_time_safe(value);

            std::string uuid(value, value + sizeof value / sizeof value[0]);

            delete value;

            return uuid;
        }
    };
}