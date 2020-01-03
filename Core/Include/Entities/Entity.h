#pragma once

#include "stdafx.h"
#include <list>
#include "Components\Component.h"

namespace BRCore
{    
    class Entity
    {
    public:
        Entity(std::string name) : m_name(name), m_components{}{};
        ~Entity();

        std::string             Name() const { return m_name; }
        void                    SetName( const std::string name ) { m_name = name; }

        void                    Update();
        void                    AddComponent( Component* component );

    private:
        std::string             m_name;
        std::list<Component*>*  m_components;
    };
}