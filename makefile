CC=g++
CXX=g++
CXXFLAGS=-std=c++17

beeTest: Grid.o Tile.o Bee.o

Grid.o: Grid.hpp Bee.o

Tile.o: Tile.hpp Bee.o

Bee.o: Bee.hpp

clean: 
		rm -rf beeTest *.o 
