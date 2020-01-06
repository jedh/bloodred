#pragma once

#include <memory>
#include <list>
#include "BRShapes.h"

namespace BRCore
{
    class IRenderer
    {
    public:
        virtual bool            Init() = 0;
        virtual void            Destroy() = 0;
        virtual void            Draw(const std::list<std::shared_ptr<BRFillRect>> rects) const = 0;
    };
}