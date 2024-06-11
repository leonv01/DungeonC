#ifndef __VECTOR2_HPP__
#define __VECTOR2_HPP__

#include <ostream>

class Vector2{
public:
    float x{};
    float y{};

    Vector2() = default;
    Vector2(float x, float y);

    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(float scalar) const;
    Vector2 operator/(float scalar) const;

    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
    Vector2& operator*=(float scalar);
    Vector2& operator/=(float scalar);

    std::ostream& operator<<(std::ostream& os) const;    
};

#endif // __VECTOR2_HPP__