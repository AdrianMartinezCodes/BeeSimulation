#include "Grid.hpp"
#include <iostream>

int main(){
    auto grid = Grid(10,10);
    std:: cout <<"grid done" << std::endl;
    auto bee = Bee(0,1);
    std::cout <<"Bee done" << std::endl;
    std::cout << bee << std::endl;
    grid.add_to_grid(bee.x_cord,bee.y_cord);
    grid.display_grid();
}