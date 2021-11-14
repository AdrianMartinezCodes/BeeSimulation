#pragma once
#include <iostream>

class Bee{ 
    private:
        std::string representation = "B";
    public: 
        int x_cord;
        int y_cord;
        Bee();
        Bee(int x, int y);
        std::string get_rep(){
            return representation;
        }
    friend auto operator << (std::ostream& os, Bee const& bee) -> std::ostream& { 
        return os << bee.representation;
    }
};