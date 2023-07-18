#ifndef BEE_H
#define BEE_H

#include "point.hpp"
#include "flower.hpp"
#include <vector>

class Bee {
public:
    Bee(double charge, const Point& location);

    double getCharge() const;
    const Point& getLocation() const;
    void randomWalk(double stepSize);
    void useAStar(std::vector<Flower>& flowers);

private:
    double charge;
    Point location;
};

#endif  // BEE_H
