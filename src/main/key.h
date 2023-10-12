#pragma once

#include <string>

namespace snipdb
{
    enum KeyType
    {
        Number,
        Guid
    };

    struct IKey
    {
        std::string name;
        KeyType type;

        template <typename T>
        T *cast()
        {
            return static_cast<T *>(this);
        }
    };

    template <typename T>
    struct Key : IKey
    {
        // Key(std::string name, KeyType type) : IKey { name, type } {};
        explicit Key(KeyType type) : IKey{type : type} {};
        // explicit Key(IKey key) : IKey(key) {}

        T value;

        bool operator<(const Key &key) const
        {
            return value < key.value;
        }

        T *cast()
        {
            return dynamic_cast<T *>(this);
        }
    };

    struct GuidKey : Key<std::string>
    {
        GuidKey() : Key(KeyType::Guid){};
    };

    struct LongKey : Key<uint64_t>
    {
        LongKey() : Key(KeyType::Number){};
    };
}
