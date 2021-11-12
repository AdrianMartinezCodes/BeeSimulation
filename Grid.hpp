#include "bee.hpp"
#include <vector>

class Grid(){
    private:
        std::vector<vector<char>> field[][];
    public: 
        Grid();
        add_to_grid(char x, char y);
        remove_from_grid(auto bee);
        ~Grid();
}