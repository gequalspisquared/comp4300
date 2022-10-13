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
    float dist(const Vec2& rhs) const;

    void normalize();

    // operator overloading
    bool operator==(const Vec2& rhs) const;
    bool operator!=(const Vec2& rhs) const;

    float operator*(const Vec2& rhs) const; // dot product

    void operator+=(const Vec2& rhs);
    void operator-=(const Vec2& rhs);
    void operator*=(const float scale);
    void operator/=(const float scale);

    Vec2 operator+(const Vec2& rhs) const;
    Vec2 operator-(const Vec2& rhs) const;
    Vec2 operator*(const float scale) const;      // scaling 
    Vec2 operator/(const float scale) const;
};

#endif