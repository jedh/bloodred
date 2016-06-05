#pragma once

namespace BRCore
{
    class IRenderer
    {
    public:
        virtual bool            Init() = 0;
        virtual void            Destroy() = 0;
        virtual void            Draw() const = 0;
    };
}