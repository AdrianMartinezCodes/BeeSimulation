#pragma once
#include "Bee.hpp"
class QueenBee : public Bee{
    private:
        std::string representation = "Q";
    public: 
        QueenBee();
        QueenBee(int x, int y);
        std::string get_rep(){
            return representation;
        }
    friend auto operator <<(std::ostream& os, QueenBee const& Bee) -> std::ostream& { 
        return os << Bee.representation;
    }
};