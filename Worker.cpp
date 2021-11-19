#include "Worker.hpp"
Worker::Worker(): Bee(){
    set_rep(representation);
}
Worker::Worker(int x, int y): Bee(x,y){
    set_rep(representation);
}