#pragma once
#include<SFML/Graphics.hpp>

class bullet {
public:
	bullet(/*int direction, sf::Vector2f pos, int atk*/);
	sf::Texture bTex;
	sf::Vector2f aim;
	int attackLevel;
	sf::Sprite bulletList[10];
};