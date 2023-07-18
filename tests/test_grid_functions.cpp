#include <catch2/catch_all.hpp>
#include "grid_functions.hpp"

TEST_CASE("Grid Functions - createGrid") {
    // Test case for createGrid function

    // Define some sample flowers and bee
    std::vector<Flower> flowers;
    flowers.emplace_back(0.5, Point(2.0, 3.0));
    flowers.emplace_back(0.3, Point(4.0, 5.0));
    Bee bee(0.7, Point(1.0, 1.0));

    // Define grid size and resolution
    int gridWidth = 10;
    int gridHeight = 10;
    double gridResolution = 1.0;

    // Call the createGrid function
    auto grid = createGrid(flowers, bee, gridWidth, gridHeight, gridResolution);
    REQUIRE(grid[3][2] == 'F'); // Check if there's a flower at row 3, column 2
    REQUIRE(grid[1][1] == 'B'); // Check if the bee is at row 1, column 1
}

TEST_CASE("Grid Functions - updateGrid") {
    // Test case for updateGrid function
    // Create a grid with a specific size and resolution
    int gridWidth = 10;
    int gridHeight = 10;
    double gridResolution = 1.0;
    std::vector<std::vector<char>> grid(gridHeight, std::vector<char>(gridWidth, '#'));

    // Create a Bee and a Flower with known positions
    Bee bee(1.0, Point(2.5, 3.5));
    Flower flower(0.5, Point(5.0, 6.0));

    // Create a vector of flowers and add the single flower to it
    std::vector<Flower> flowers;
    flowers.push_back(flower);

    // Update the grid with Bee and Flower positions
    updateGrid(grid, flowers, bee, gridWidth, gridHeight, gridResolution);

    // Check if the Bee and Flower positions are marked correctly on the grid
    REQUIRE(grid[3][2] == 'B'); // Bee at (2.5, 3.5) -> grid[3][2]
    REQUIRE(grid[6][5] == 'F'); // Flower at (5.0, 6.0) -> grid[6][5]
    REQUIRE(grid[0][0] == '#'); // Empty cell at (0, 0) -> grid[0][0]
}