#pragma once

namespace BRCore
{
    class Vector2
    {
    public:
        Vector2() { this->x = x; this->y = y; }
        Vector2( float x, float y ) { this->x = x; this->y = y; }
        //~Vector2();

        static Vector2          Add( const Vector2& vectorLHS, const Vector2& vectorRHS );
        static Vector2          Subtract( const Vector2& vectorLHS, const Vector2& vectorRHS );

        void                    Add( const Vector2& vectorRHS );
        void                    Subtract( const Vector2& vectorRHS );

        float                   x;
        float                   y;
    };
}