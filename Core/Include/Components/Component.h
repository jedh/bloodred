#pragma once

#include "stdafx.h"

namespace BRCore
{
    class Entity;

    class Component
    {
    public:
        virtual             std::string Name() const = 0;
        virtual             void Update() = 0;

        const               Entity* Owner() const { return m_owner; }
        // TODO: Possibly remove function and create the owner relationship in a factory or some other initialization flow.
        const               void SetOwner( const Entity* entity ) { m_owner = entity; }

    private:
        const               Entity* m_owner;
    };
}