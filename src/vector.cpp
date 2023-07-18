#include "vector.hpp"
#include <ostream>

Vector::Vector() : x(0.0), y(0.0) {}

Vector::Vector(double x, double y) : x(x), y(y) {}

double Vector::getX() const {
    return x;
}

double Vector::getY() const {
    return y;
}

std::ostream& operator<<(std::ostream& os, const Vector& vector) {
    os << "(" << vector.getX() << ", " << vector.getY() << ")";
    return os;
}