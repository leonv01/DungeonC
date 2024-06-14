#include "util/Vector2.hpp"

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2 Vector2::operator+(const Vector2& other) const {
    return {x + other.x, y + other.y};
}

Vector2 Vector2::operator-(const Vector2& other) const {
    return {x - other.x, y - other.y};
}

Vector2 Vector2::operator*(float scalar) const {
    return {x * scalar, y * scalar};
}

Vector2 Vector2::operator/(float scalar) const {
    return {x / scalar, y / scalar};
}

Vector2& Vector2::operator+=(const Vector2& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2& Vector2::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2& Vector2::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector2& vector) {
    os << "(" << vector.x << ", " << vector.y << ")";
    return os;
}