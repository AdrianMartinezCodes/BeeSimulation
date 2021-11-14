CC=g++
CXX=g++
CXXFLAGS=-std=c++17 -g

beeTest: Grid.o Tile.o BeeHive.o Worker.o QueenBee.o Bee.o

Grid.o: Grid.hpp Bee.o

Tile.o: Tile.hpp Bee.o

BeeHive.o: Worker.o QueenBee.o

QueenBee.o: Bee.o

Worker.o: Bee.o

Bee.o: Bee.hpp

clean: 
		rm -rf beeTest *.o 
