#include "QueenBee.hpp"
QueenBee::QueenBee(): Bee(0,0){
    set_rep(representation);
}
QueenBee::QueenBee(int x, int y): Bee(x,y) {
    set_rep(representation);
}