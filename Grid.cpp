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

void Grid::add_to_grid(int x,int y){
    Bee toAdd{x,y};
    this->field[x][y] = Tile(toAdd);
}

/*Grid::~Grid(){
    for(int i; i < this->field.size();++i){
        for(int j; j < this->field[i].size();++j){
            i;
        }
    }
}*/
void Grid::display_grid(){
    for(int i = 0; i < this->field.size();++i){
        for(int j = 0; j < this->field.at(i).size();j++){
            std::cout << this->field.at(i).at(j);
        }
        std::cout << std::endl;
    }
}