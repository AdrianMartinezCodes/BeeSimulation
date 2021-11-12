#include "Grid.hpp"
#include <vector>

class Grid(){
    Grid(){
        field = std::vector<vector<char>;
    }


    ~Grid(){
        for(int x = 0; x < field.length(); x++){
            for(int y = x; y < field[0].length(); y++){
                delete grid[x][y];
            }
        }
    }
}