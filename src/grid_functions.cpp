#include "grid_functions.hpp"

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