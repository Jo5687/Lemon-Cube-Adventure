#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class player{
public:

	player(int health, int level, int xp, int damage);
	int pHealth;
	int pLevel;
	int pXP;
	int pDamage;
	sf::Texture idle;
	sf::Texture up;
	sf::Texture left;
	sf::Texture right;
	sf::Texture shoot;
	sf::Texture reload;
	sf::Texture hurt;
	std::string pHealthText();
	std::string pLevelText();
	sf::Texture idleH;
	sf::Texture upH;
	sf::Texture leftH;
	sf::Texture rightH;
	sf::Texture shootH;
	sf::Texture reloadH;
	void die();
};