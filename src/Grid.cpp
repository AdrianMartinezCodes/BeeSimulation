#include "Grid.hpp"
#include <string>
#include <vector>
#include <iostream>

Grid::Grid(int x, int y){
    this->field = std::vector<std::vector<Tile>>(x);
    for(int i = 0; i < x; ++i){
        this->field.at(i) = std::vector<Tile>(y);
    }
}

void Grid::add_to_grid(Bee bee){
    this->field[bee.x_cord][bee.y_cord] = Tile(bee);
}

void Grid::add_to_grid(BeeHive bee_hive){
    this->field[bee_hive.x_cord][bee_hive.y_cord] = Tile(bee_hive);
}

void Grid::display_grid(){
    for(int i = 0; i < this->field.size();++i){
        for(int j = 0; j < this->field.at(i).size();j++){
            std::cout << this->field.at(i).at(j);
        }
        std::cout << std::endl;
    }
}
Grid::~Grid(){
    this->field.clear();
}