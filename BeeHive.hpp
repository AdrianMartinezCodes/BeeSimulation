#pragma once
#include "Worker.hpp"
#include "QueenBee.hpp"
#include <vector>
struct BeeHive{
    /* data */
    const std::string representation = "H";
    int x_cord;
    int y_cord;
    int bee_counter;
    QueenBee Queen;
    //std::vector<Worker> workerVec; 
    BeeHive();
    BeeHive(int x, int y);
    std::string get_rep(){
        return representation;
    }
    friend auto operator << (std::ostream& os, BeeHive const& m) -> std::ostream& { 
        return os << m.representation;
    }
};
