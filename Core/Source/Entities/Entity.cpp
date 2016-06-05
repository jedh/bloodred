#include <Entities\Entity.h>

namespace BRCore
{
    Entity::Entity()
    {

    }

    Entity::~Entity()
    {

    }

    void Entity::Update()
    {
        for ( auto component : *m_components )
        {
            component->Update();
        }
    }

    void Entity::AddComponent( Component* component )
    {
        m_components->push_back( component );
        component->SetOwner( this );
    }
}