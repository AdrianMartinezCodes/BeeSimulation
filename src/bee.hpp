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
    // Move the bee randomly within the grid with wrapping
    void randomWalkWrap(double stepSize, int gridWidth, int gridHeight);
    void useAStar(std::vector<Flower>& flowers);
    // Update the bee's location using A* algorithm with wrapping
    void useAStarWrap(std::vector<Flower>& flowers, int gridWidth, int gridHeight);



private:
    double charge;
    Point location;
};

#endif  // BEE_H
