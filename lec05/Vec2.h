#pragma once

class Vec2
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

    Vec2 operator+(const Vec2& rhs) const;
    void operator+=(const Vec2& rhs);
};