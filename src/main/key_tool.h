#pragma once

#include "key.h"

#include <memory>

namespace snipdb
{
    class KeyTool
    {
    public:
        virtual ~KeyTool() = default;
        virtual IKey nextKey() const = 0;
    };

    class KeyFile;
    class NumberKeyTool : public KeyTool
    {
    private:
        std::shared_ptr<KeyFile> keyFile;

    public:
        NumberKeyTool(const KeyFile *keyFile);
        // NumberKeyTool(const NumberKeyTool&) = delete;
        // NumberKeyTool& operator=(const NumberKeyTool&) = delete;

        IKey nextKey() const;
    };

    class GuidKeyTool : public KeyTool
    {
    public:
        IKey nextKey() const;
    };
}