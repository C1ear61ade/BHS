/*
 * Creator: C1ear61ade
 * Purpose: Implementation of functions of the Vector3 class to be used in main.cpp
 */

#include "Vector3.h"
#include <cmath>

Vector3::Vector3(double x, double y, double z): x(x), y(y), z(z){}

double Vector3::length() const {
    return std::sqrt(x*x + y*y + z*z);
}

Vector3 Vector3::normalize() const {
    if (length() == 0) { // Prevent {0,0,0} from going through this / length() because its undefined.
        return Vector3{0, 0, 0};
    };

    return *this / length();

}

double Vector3::dotProduct(const Vector3 &other) const {
    return x * other.x + y * other.y + z * other.z;

}

Vector3 Vector3::crossProduct(const Vector3 &other) const {
    return Vector3{y * other.z - z * other.y,z * other.x - x * other.z,x * other.y - y * other.x};

}

Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3{x + other.x, y + other.y, z + other.z};

}

Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3{x - other.x, y - other.y, z - other.z};

}

Vector3 Vector3::operator*(double scalar) const {
    return Vector3{x * scalar, y * scalar, z * scalar};

}

Vector3 Vector3::operator/(double scalar) const {
    return Vector3{x / scalar, y / scalar, z / scalar};

}