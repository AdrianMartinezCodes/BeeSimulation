#include "point.hpp"
#include <ostream>

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.getX() << ", " << point.getY() << ")";
    return os;
}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}