#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class title {
public:
	title();
	sf::Font mainF;
	sf::Text mainT;
	std::string titleText;
	sf::Text highScore;
	sf::String gettingScore(int scr);
};
