#include "Bee.hpp"
#include <string>
#include <iostream>
class Tile{
    public:
        std::string tile;
        Tile();
        Tile(Bee);
    friend auto operator << (std::ostream& os, Tile const& m) -> std::ostream& { 
        return os << m.tile;
    }
};