#pragma once
#include <vector>
#include "point.hpp"
#include "flower.hpp"
#include "bee.hpp"
#include <iostream>

std::vector<std::vector<char>> createGrid(const std::vector<Flower>& flowers, const Bee& bee, int gridWidth, int gridHeight, double gridResolution);
void updateGrid(std::vector<std::vector<char>>& grid, const std::vector<Flower>& flowers, const Bee& bee, int gridWidth, int gridHeight, double gridResolution);
void printGrid(const std::vector<std::vector<char>>& grid);