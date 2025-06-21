#include "pch.h"
#include "title.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;

title::title() {
	mainF.loadFromFile("fonts/SuperLegendBoy-4w8Y.ttf");
	mainT.setFont(mainF);
	highScore.setFont(mainF);
	titleText = "Lemon Cube - Press Z to Start";
	mainT.setString(titleText);
	mainT.setFillColor(sf::Color::White);
	highScore.setFillColor(sf::Color::White);
	mainT.setCharacterSize(40);
	highScore.setCharacterSize(25);
	mainT.setPosition(320, 360);
	mainT.setOrigin(100, 50);
	highScore.setPosition(320, 360);
	highScore.setOrigin(-160, 0);
}

sf::String title::gettingScore(int scr) {
	string dis;
	dis = std::to_string(scr);
	return dis;
}