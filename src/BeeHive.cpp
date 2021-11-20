#include "BeeHive.hpp"
BeeHive::BeeHive():x_cord(0),y_cord(0){
    //std::vector<Bee> workerVec = std::vector<Bee>();
    QueenBee Queen = QueenBee();
}
BeeHive::BeeHive(int x, int y): x_cord(x), y_cord(y){
    //std::vector<Bee> workerVec = std::vector<Bee>();
    QueenBee Queen = QueenBee(x,y);
}