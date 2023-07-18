#ifndef FLOWER_H
#define FLOWER_H

#include "point.hpp"
#include "vector.hpp"

class Flower {
public:
    Flower(double negCharge, const Point& location);

    double getNegativeCharge() const;
    const Point& getLocation() const;
    Vector getVectorTo(const Point& point) const;
    double getDistanceSquaredTo(const Point& point) const; 

private:
    double negCharge;
    Point location;
};

#endif  // FLOWER_H
