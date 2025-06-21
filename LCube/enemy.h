#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class enemy {
public:
	enemy(int h, int d);
	sf::Sprite spawn();
	int eHealth;
	int eDamage;
	int mult = 0;
	double speedMult = 1.5;
	sf::Texture idle;
	sf::Texture attack;
	sf::Texture hit;
	sf::Texture fly;
	sf::Vector2f follow(sf::Vector2f pPos, sf::Sprite &eSprite, bool &collide);
	sf::Vector2f ePos;
	void respawn(sf::Sprite &theSprite, sf::Vector2f posToGo);
	std::string healthText();
};