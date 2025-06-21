#include "pch.h"
#include "ui.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
using namespace std;

ui::ui() {
	mainFont.loadFromFile("fonts/SuperLegendBoy-4w8Y.ttf");
	playerHealth.setFont(mainFont);
	enemyHealth.setFont(mainFont);
	playerLevel.setFont(mainFont);
	bC.setFont(mainFont);
	Hs.setFont(mainFont);
	enemyHealth.setCharacterSize(50);
	playerHealth.setCharacterSize(50);
	playerLevel.setCharacterSize(80);
	bC.setCharacterSize(80);
	Hs.setCharacterSize(40);
	enemyHealth.setFillColor(sf::Color::Black);
	playerHealth.setFillColor(sf::Color::Black);
	playerLevel.setFillColor(sf::Color::Black);
	bC.setFillColor(sf::Color::Black);
	Hs.setFillColor(sf::Color::White);
	enemyHealth.setOrigin(62, 200);
	playerHealth.setOrigin(62, 200);
	playerLevel.setOrigin(-715, 500);
	bC.setOrigin(-795, 385);
	string textHealth;
	uiTex.loadFromFile("Sprites/ui.png");
	uiSprite.setTexture(uiTex);
	uiSprite.setScale(8, 8);
	uiSprite.setOrigin(-55, 63);
	Hs.setPosition(320, 360);
	Hs.setOrigin(200, 0);
	bTex.loadFromFile("Sprites/aCount.png");
	ball.setTexture(bTex);
	ball.setScale(8, 8);
	ball.setOrigin(-80, 50);
}

std::string ui::score(int score) {
	string scoreDisplay;
	score = score * 100;
	scoreDisplay = std::to_string(score);
	return scoreDisplay;
}

std::string ui::ballCount(int count) {
	string diz;
	diz = std::to_string(count);
	return diz;
}