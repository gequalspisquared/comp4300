#ifndef VEC2_H
#define VEC2_H

class Vec2
{
public:
    float x = 0;
    float y = 0;

    Vec2();
    Vec2(float xin, float yin);

    // methods
    float mag2() const;
    float mag() const;

    void normalize();

    // operator overloading
    bool operator==(const Vec2& rhs) const;
    bool operator!=(const Vec2& rhs) const;

    float operator*(const Vec2& rhs) const; // dot product

    void operator+=(const Vec2& rhs);
    void operator-=(const Vec2& rhs);

    Vec2 operator+(const Vec2& rhs) const;
    Vec2 operator-(const Vec2& rhs) const;
    Vec2 operator*(float scale) const;      // scaling 
    Vec2 operator/(float scale) const;
};

#endif