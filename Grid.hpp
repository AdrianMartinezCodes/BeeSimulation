#pragma once
#include "Tile.hpp"
#include <vector>

class Grid{
    private:
        std::vector<std::vector<Tile>> field;
    public: 
        Grid(int x, int y);
        void add_to_grid(Bee bee);
        void add_to_grid(BeeHive bee_hive);
        void remove_from_grid(Bee bee);
        ~Grid();
        void display_grid();
};