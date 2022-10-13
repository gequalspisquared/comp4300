#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <SFML/Graphics.hpp>

#include "Vec2.h"

class CTransform
{
public:
    Vec2 pos  = {0.0f, 0.0f};
    Vec2 vel  = {0.0f, 0.0f};
    float ang = 0.0f; // angle

    CTransform(const Vec2& position, const Vec2& velocity, float angle)
        : pos(position)
        , vel(velocity)
        , ang(angle)
    {
    }
};

class CShape
{
public:
    sf::CircleShape circle;

    CShape(float radius, int points, const sf::Color& fill, 
           const sf::Color& outline, float thickness)
        : circle(radius, points)
    {
        circle.setFillColor(fill);
        circle.setOutlineColor(outline);
        circle.setOutlineThickness(thickness);
        circle.setOrigin(radius, radius);
    }
};

class CCollision
{
public: 
    float radius = 0;

    CCollision(float r)
        : radius(r)
    {
    }
};

class CScore
{
public:
    int score = 0;

    CScore(int s)
        : score(s)
    {
    }
};

class CLifespan
{
public:
    int remaining = 0; // amount of lifespan remaining on the entity
    int total     = 0; // the total initial amount of lifespan

    CLifespan(int tot)
        : remaining(tot)
        , total(tot)
    {
    }
};

class CInput
{
public:
    bool up    = false;
    bool down  = false;
    bool left  = false;
    bool right = false;
    bool shoot = false;

    CInput() {}
};

#endif