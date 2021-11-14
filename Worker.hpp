#pragma once
#include "Bee.hpp"
class Worker: public Bee{
    private:
        std::string representation = "W";
        enum class worker_type {
        clean,
        feedOne,
        feedTwo,
        recieve,
        beeswax,
        field,
        death
        };
    public:
        Worker();
        Worker(int x, int y);
        std::string get_rep(){
            return representation;
        }
    friend auto operator <<(std::ostream& os, Worker const& Bee) -> std::ostream& { 
        return os << Bee.representation;
    }
};