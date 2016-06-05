#include "Foundation\Vector2.h"

namespace BRCore
{
    Vector2 Vector2::Add( const Vector2& vectorLHS, const Vector2& vectorRHS )
    {
        Vector2 returnVector = Vector2();
        returnVector.x = vectorLHS.x + vectorRHS.x;
        returnVector.y = vectorLHS.y + vectorRHS.y;

        return returnVector;
    };

    Vector2 Vector2::Subtract( const Vector2& vectorLHS, const Vector2 & vectorRHS )
    {
        Vector2 returnVector = Vector2();
        returnVector.x = vectorLHS.x - vectorRHS.x;
        returnVector.y = vectorLHS.y - vectorRHS.y;

        return returnVector;
    };

    void Vector2::Add( const Vector2& vectorRHS )
    {
        this->x += vectorRHS.x;
        this->y += vectorRHS.y;
    };

    void Vector2::Subtract( const Vector2& vectorRHS )
    {
        this->x -= vectorRHS.x;
        this->y -= vectorRHS.y;
    }
}