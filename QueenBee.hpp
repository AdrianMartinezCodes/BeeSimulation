#pragma once
#include "Bee.hpp"
class QueenBee : public Bee{
    private:
        std::string representation = "Q";
    public: 
        QueenBee();
        QueenBee(int x, int y);
};