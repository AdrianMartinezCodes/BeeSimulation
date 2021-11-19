#pragma once
#include "Bee.hpp"
class Worker: public Bee{
    private:
        const std::string representation = "W";
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
};