#include "point.hpp"
#include "flower.hpp"
#include "bee.hpp"
#include <iostream>
#include <vector>
#include <cmath>


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
std::vector<std::vector<char>> createGrid(const std::vector<Flower>& flowers, const Bee& bee, int gridWidth, int gridHeight, double gridResolution) {
    int numCols = static_cast<int>(gridWidth / gridResolution);
    int numRows = static_cast<int>(gridHeight / gridResolution);

    // Initialize the grid with empty cells (#)
    std::vector<std::vector<char>> grid(numRows, std::vector<char>(numCols, '#'));

    // Mark cells containing flowers (F)
    for (const Flower& flower : flowers) {
        int x = static_cast<int>(flower.getLocation().getX() / gridResolution);
        int y = static_cast<int>(flower.getLocation().getY() / gridResolution);
        if (x >= 0 && x < numCols && y >= 0 && y < numRows) {
            grid[y][x] = 'F';
        }
    }

    // Mark the cell containing the bee (B)
    int beeX = static_cast<int>(bee.getLocation().getX() / gridResolution);
    int beeY = static_cast<int>(bee.getLocation().getY() / gridResolution);
    if (beeX >= 0 && beeX < numCols && beeY >= 0 && beeY < numRows) {
        grid[beeY][beeX] = 'B';
    }

    return grid;
}

void updateGrid(std::vector<std::vector<char>>& grid, const std::vector<Flower>& flowers, const Bee& bee, int gridWidth, int gridHeight, double gridResolution) {
    int numCols = static_cast<int>(gridWidth / gridResolution);
    int numRows = static_cast<int>(gridHeight / gridResolution);

    // Reset the grid with empty cells (#)
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), '#');
    }

    // Mark cells containing flowers (F)
    for (const Flower& flower : flowers) {
        int x = static_cast<int>(flower.getLocation().getX() / gridResolution);
        int y = static_cast<int>(flower.getLocation().getY() / gridResolution);
        if (x >= 0 && x < numCols && y >= 0 && y < numRows) {
            grid[y][x] = 'F';
        }
    }

    // Mark the cell containing the bee (B)
    int beeX = static_cast<int>(bee.getLocation().getX() / gridResolution);
    int beeY = static_cast<int>(bee.getLocation().getY() / gridResolution);
    if (beeX >= 0 && beeX < numCols && beeY >= 0 && beeY < numRows) {
        grid[beeY][beeX] = 'B';
    }
}

// Function to print the grid representation
void printGrid(const std::vector<std::vector<char>>& grid) {
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}


int main() {
    srand(time(0));
    // Prompt the user to set grid size attributes
    std::cout << "Enter the grid width: ";
    std::string inputWidth;
    std::getline(std::cin, inputWidth);
    int GRID_WIDTH = std::stoi(inputWidth);

    std::cout << "Enter the grid height: ";
    std::string inputHeight;
    std::getline(std::cin, inputHeight);
    int GRID_HEIGHT = std::stoi(inputHeight);

    std::cout << "Enter the grid resolution: ";
    std::string inputResolution;
    std::getline(std::cin, inputResolution);
    double GRID_RESOLUTION = std::stod(inputResolution);

    std::vector<Flower> flowers;
    for (int i = 0; i < 10; ++i) {
        double negCharge = std::rand() / double(RAND_MAX);
        double flowerX = std::rand() / double(RAND_MAX) * GRID_WIDTH;
        double flowerY = std::rand() / double(RAND_MAX) * GRID_HEIGHT;
        Point location = Point(flowerX, flowerY);
        flowers.emplace_back(negCharge, location);
    }

    double beeCharge = std::rand() / double(RAND_MAX);
    double beeX = std::rand() / double(RAND_MAX) * GRID_WIDTH;
    double beeY = std::rand() / double(RAND_MAX) * GRID_HEIGHT;
    Bee bee(beeCharge, Point(beeX, beeY));

    auto grid = createGrid(flowers, bee,GRID_WIDTH,GRID_HEIGHT,GRID_RESOLUTION);
    int stepCount = 0;
    int maxSteps = 100; // Set the maximum number of steps here
    bool autoRun = false; // Set to true to automatically run the program, false for manual step

    while (bee.getCharge() > 0 && !flowers.empty()) {
        if (!autoRun) {
            std::cout << "Press Enter to continue to the next step, type 'auto' for automatic mode, or enter any other input to quit: ";
            std::string input;
            std::getline(std::cin, input);

            if (input == "auto") {
                autoRun = true;
                std::cout << "Automatically running the simulation..." << std::endl;
            } else if (!input.empty()) {
                std::cout << "Quitting the program." << std::endl;
                break;
            }
        }

        if (!autoRun) {
            // If not auto-run, show the current step count and the grid representation
            std::cout << "Step " << stepCount << std::endl;
        }
        updateGrid(grid, flowers, bee,GRID_WIDTH,GRID_HEIGHT,GRID_RESOLUTION);;
        printGrid(grid);
        // Run the bee's movement
        if (bee.getCharge() < 0.5) {
            bee.useAStarWrap(flowers, GRID_WIDTH, GRID_HEIGHT);
        } else {
            bee.randomWalkWrap(1,GRID_WIDTH,GRID_HEIGHT);
        }

        ++stepCount;

        // Stop if the maximum number of steps is reached
        if (autoRun && stepCount >= maxSteps) {
            break;
        }
    }

    return 0;
}
