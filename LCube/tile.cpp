#include "pch.h"
#include "tile.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

tile::tile() {
	grass.loadFromFile("Sprites/grass.png");
	rock.loadFromFile("Sprites/rock.png");
	water.loadFromFile("Sprites/water.png");
	tree.loadFromFile("Sprites/actualTree.png");
	flowers.loadFromFile("Sprites/flowers.png");
	grass2.loadFromFile("Sprites/grass2.png");
	flowers2.loadFromFile("Sprites/flowers2.png");
}

