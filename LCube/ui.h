#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class ui {
public: 
	ui();
	sf::Text playerHealth;
	sf::Text enemyHealth;
	sf::Text playerLevel;
	sf::Text bC;
	sf::Font mainFont;
	sf::Texture uiTex;
	sf::Sprite uiSprite;
	sf::Text Hs;
	std::string score(int score);
	sf::Sprite ball;
	sf::Texture bTex;
	sf::Text count; 
	std::string ballCount(int count);
};