#pragma once
#include <iostream>

class Bee{ 
    private:
        const std::string REPRESENTATION = "B";
        std::string representation = REPRESENTATION;
    public: 
        int x_cord;
        int y_cord;
        Bee();
        Bee(int x, int y);
        std::string get_rep(){
            return representation;
        }
        //used in child classes
        void set_rep(std::string name);
    friend auto operator << (std::ostream& os, Bee const& bee) -> std::ostream& { 
        return os << bee.representation;
    }
};