#include "bee.hpp"
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <cmath>

Bee::Bee(double charge, const Point& location) : charge(charge), location(location) {}

double Bee::getCharge() const {
    return charge;
}

const Point& Bee::getLocation() const {
    return location;
}

void Bee::randomWalk(double stepSize) {
    double dx = stepSize * (2 * std::rand() / double(RAND_MAX) - 1);
    double dy = stepSize * (2 * std::rand() / double(RAND_MAX) - 1);
    location = Point(location.getX() + dx, location.getY() + dy);
}

void Bee::randomWalkWrap(double stepSize, int gridWidth, int gridHeight) {
    double dx = stepSize * (2 * std::rand() / double(RAND_MAX) - 1);
    double dy = stepSize * (2 * std::rand() / double(RAND_MAX) - 1);

    // Wrap the bee's location around the grid
    double wrappedX = std::fmod(location.getX() + dx + gridWidth, gridWidth);
    double wrappedY = std::fmod(location.getY() + dy + gridHeight, gridHeight);

    location = Point(wrappedX, wrappedY);
}

void Bee::useAStar(std::vector<Flower>& flowers) {
    const Flower* nearestFlower = nullptr;
    double nearestDistanceSquared = std::numeric_limits<double>::max(); // Use squared distance

    for (const Flower& flower : flowers) {
        double distanceSquared = flower.getDistanceSquaredTo(location); // Use squared distance
        if (distanceSquared < nearestDistanceSquared) {
            nearestFlower = &flower;
            nearestDistanceSquared = distanceSquared;
        }
    }

    if (nearestFlower != nullptr) {
        Vector vectorField = Vector(0, 0);

        for (const Flower& flower : flowers) {
            Vector vectorToBee = flower.getVectorTo(location);
            double strength = flower.getNegativeCharge() / flower.getDistanceSquaredTo(location); // Use squared distance
            vectorField = Vector(vectorField.getX() + strength * vectorToBee.getX(), vectorField.getY() + strength * vectorToBee.getY());
        }

        double stepSize = charge / std::sqrt(nearestDistanceSquared); // Calculate the step size with square root
        location = Point(location.getX() + stepSize * vectorField.getX(), location.getY() + stepSize * vectorField.getY());

        charge += nearestFlower->getNegativeCharge();

        // Use std::find_if to find the element based on its memory address
        auto it = std::find_if(flowers.begin(), flowers.end(), [&nearestFlower](const Flower& flower) {
            return &flower == nearestFlower;
        });

        if (it != flowers.end()) {
            // Erase the element using the iterator returned by std::find_if
            flowers.erase(it);
        }
    }
}
void Bee::useAStarWrap(std::vector<Flower>& flowers, int gridWidth, int gridHeight){
    // Use the existing useAStar function for wrapping
    useAStar(flowers);

    // Wrap the bee's location around the grid
    double wrappedX = std::fmod(location.getX() + gridWidth, gridWidth);
    double wrappedY = std::fmod(location.getY() + gridHeight, gridHeight);

    location = Point(wrappedX, wrappedY);
}
