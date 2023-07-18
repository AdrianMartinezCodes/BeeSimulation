#include "point.hpp"
#include "flower.hpp"
#include "bee.hpp"
#include <iostream>
#include <vector>
#include <cmath>

// Define the grid dimensions and resolution
const int GRID_WIDTH = 10;
const int GRID_HEIGHT = 10;
const double GRID_RESOLUTION = 0.1;

Vector getVectorField(const std::vector<Flower>& flowers, const Point& point) {
    Vector vectorField = Vector(0.0, 0.0);

    for (const Flower& flower : flowers) {
        Vector vectorToBee = flower.getVectorTo(point);
        double distanceSquared = flower.getDistanceSquaredTo(point);
        double strength = flower.getNegativeCharge() / distanceSquared;
        vectorField = Vector(vectorField.getX() + strength * vectorToBee.getX(), vectorField.getY() + strength * vectorToBee.getY());
    }
    return vectorField;
}

// Function to create the grid representation
std::vector<std::vector<Vector>> createGrid(const std::vector<Flower>& flowers) {
    std::vector<std::vector<Vector>> grid(GRID_WIDTH, std::vector<Vector>(GRID_HEIGHT));

    for (int x = 0; x < GRID_WIDTH; ++x) {
        for (int y = 0; y < GRID_HEIGHT; ++y) {
            Point point(x * GRID_RESOLUTION, y * GRID_RESOLUTION);
            grid[x][y] = getVectorField(flowers, point);
        }
    }

    return grid;
}

// Function to print the grid representation
void printGrid(const std::vector<std::vector<Vector>>& grid) {
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            std::cout << "(" << grid[x][y].getX() << ", " << grid[x][y].getY() << ") ";
        }
        std::cout << std::endl;
    }
}


int main() {
    std::vector<Flower> flowers;
    for (int i = 0; i < 10; ++i) {
        double negCharge = std::rand() / double(RAND_MAX);
        Point location = Point(std::rand() / double(RAND_MAX), std::rand() / double(RAND_MAX));
        flowers.emplace_back(negCharge, location);
    }

    Bee bee(std::rand() / double(RAND_MAX), Point(std::rand() / double(RAND_MAX), std::rand() / double(RAND_MAX)));

    int stepCount = 0;
    int maxSteps = 100; // Set the maximum number of steps here
    bool autoRun = false; // Set to true to automatically run the program, false for manual step

    while (bee.getCharge() > 0 && !flowers.empty()) {
        if (!autoRun) {
            // If not auto-run, prompt the user to manually step through the simulation
            std::string input;
            std::cout << "Press Enter to continue to the next step, or type 'auto' to run automatically: ";
            std::getline(std::cin, input);

            if (input == "auto") {
                autoRun = true;
                std::cout << "Automatically running the simulation..." << std::endl;
            }
        }

        if (!autoRun) {
            // If not auto-run, show the current step count and the grid representation
            std::cout << "Step " << stepCount << std::endl;
            auto grid = createGrid(flowers);
            printGrid(grid);
        }

        // Run the bee's movement
        if (bee.getCharge() < 0.5) {
            bee.useAStar(flowers);
        } else {
            bee.randomWalk(0.1);
        }

        ++stepCount;

        // Stop if the maximum number of steps is reached
        if (autoRun && stepCount >= maxSteps) {
            break;
        }
    }

    return 0;
}
