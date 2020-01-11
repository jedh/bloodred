#pragma once

#include <memory>
#include <list>
#include "Foundation/BRShapes.h"
#include "Sprites/Sprite.h"
#include <SDL.h>
#include <string>
#include "Foundation/Vector2.h"

namespace BRCore
{
    class IRenderer
    {
    public:
        virtual bool            Init() = 0;
        virtual void            Destroy() = 0;
        virtual void            Draw(const std::list<std::shared_ptr<BRFillRect>>& rects, const std::list<std::shared_ptr<Sprite>>& sprites) const = 0;
        virtual SDL_Texture*    GetTexture(std::string path) const = 0;
        virtual BRCore::Vector2 GetLogicalRenderSize() const = 0;
    };
}