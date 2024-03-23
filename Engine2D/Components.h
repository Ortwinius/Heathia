#pragma once

#include "raylib.h"

class CTransform
{
public:
    Vector2 m_position = { 0.0f, 0.0f };
    Vector2 m_scale = { 1.0f, 1.0f };
    Vector2 m_velocity = { 0.0f, 0.0f };
    float m_rotation = 0.0f;

    // constructor for initializing values
    CTransform(const Vector2& position, const Vector2& scale, const Vector2& velocity, float rotation)
        : m_position(position)
        , m_scale(scale)
        , m_velocity(velocity)
        , m_rotation(rotation)
    {}
};

class CShape
{
public:
    Rectangle m_rectangle;

    CShape(const Vector2& position, const Vector2& scale)
        : m_rectangle({ position.x, position.y, scale.x, scale.y })
    {}

    // standard constructor
    CShape()
        : m_rectangle({ 0.0f, 0.0f, 100.0f, 100.0f })
    {}
};

class CBoundingBox
{
public:
    Vector2 size;
    Vector2 halfSize;
    CBoundingBox(const Vector2 &s)
        : size(s), halfSize({ s.x / 2, s.y / 2 })
    {}
};
class CCollision
{
public:
    float m_radius;
    CCollision(const float& radius)
        : m_radius(radius)
    {}
};

class CInput
{
public:
    bool up = false;
    bool left = false;
    bool right = false;
    bool down = false;
    bool shoot = false;

    CInput() {}
};
class CLifespan
{

};
/*
* class Vec2
{
public:
    float x = 0;
    float y = 0;

    Vec2() {}

    Vec2(float xin, float yin)
        : x(xin)
        , y(yin)
    {
    }

    Vec2 operator + (const Vec2& rhs) const
    {
        return Vec2(x + rhs.x, y + rhs.y);
    }

    void operator += (const Vec2& rhs)
    {
        x += rhs.x;
        y += rhs.y;

    }

    Vec2& scale(float s)
    {
        x *= s;
        y *= s;
        return *this;
    }

    Vec2& rotate(float deg)
    {
        return *this;
    }

    Vec2& add(const Vec2& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
};
*/