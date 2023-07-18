#include "flower.hpp"
#include <cmath>

Flower::Flower(double negCharge, const Point& location) : negCharge(negCharge), location(location) {}

double Flower::getNegativeCharge() const {
    return negCharge;
}

const Point& Flower::getLocation() const {
    return location;
}

Vector Flower::getVectorTo(const Point& point) const {
    Vector vector;
    double distanceSquared = getDistanceSquaredTo(point);

    if (distanceSquared == 0) {
        vector = Vector(0, 0);
    } else {
        vector = Vector((point.getX() - location.getX()) / distanceSquared,
                        (point.getY() - location.getY()) / distanceSquared);
    }

    return vector;
}
double Flower::getDistanceSquaredTo(const Point& point) const {
    return std::pow(point.getX() - location.getX(), 2) + std::pow(point.getY() - location.getY(), 2);
}
