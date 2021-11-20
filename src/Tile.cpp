#include "Tile.hpp"
Tile::Tile(): tile("."){}
Tile::Tile(Bee bee): tile(bee.get_rep()){}
Tile::Tile(BeeHive bee_hive):tile(bee_hive.get_rep()){}