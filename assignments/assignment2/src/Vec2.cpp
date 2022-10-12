#include <cmath>

#include "../include/Vec2.h"

Vec2::Vec2() {}

Vec2::Vec2(float xin, float yin)
    : x(xin)
    , y(yin)
{
}

float Vec2::mag2() const
{
    return x*x + y*y;
}

float Vec2::mag() const
{
    return sqrtf(mag2());
}

void Vec2::normalize()
{
    float length = mag();
    x /= length;
    y /= length;
}

bool Vec2::operator==(const Vec2& rhs) const
{
    if (x == rhs.x && y == rhs.y)
        return true;
    return false;
}

bool Vec2::operator!=(const Vec2& rhs) const
{
    if (x != rhs.x || y != rhs.y)
        return true;
    return false;
}

void Vec2::operator+=(const Vec2& rhs) 
{
    x += rhs.x;
    y += rhs.y;
}

void Vec2::operator-=(const Vec2& rhs) 
{
    x -= rhs.x;
    y -= rhs.y;
}

// dot product
float Vec2::operator*(const Vec2& rhs) const
{
    return x*rhs.x + y*rhs.y;
}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
    return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 Vec2::operator-(const Vec2& rhs) const
{
    return Vec2(x - rhs.x, y - rhs.y);
}

Vec2 Vec2::operator*(float scale) const
{
    return Vec2(x*scale, y*scale);
}

Vec2 Vec2::operator/(float scale) const
{
    return Vec2(x/scale, y/scale);
}