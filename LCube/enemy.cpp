#include "pch.h"
#include "enemy.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

enemy::enemy(int h, int d) {
	idle.loadFromFile("Sprites/enemy.png");
	attack.loadFromFile("Sprites/enemyAttack.png");
	hit.loadFromFile("Sprites/enemyHit.png");
	fly.loadFromFile("Sprites/enemyFly.png");
	eHealth = h;
	eDamage = d;
}

sf::Sprite enemy::spawn() {
	sf::Sprite enemySprite;
	enemySprite.setTexture(idle);
	enemySprite.setScale(8, 8);
	enemySprite.setPosition(3200, 3200);
	enemySprite.setOrigin(12, 13.5);
	return enemySprite;
}

sf::Vector2f enemy::follow(sf::Vector2f pPos, sf::Sprite &eSprite, bool &collide) {
	sf::Vector2f fDirection;
	ePos = eSprite.getPosition();
	float xPos = pPos.x - ePos.x;
	float yPos = pPos.y - ePos.y;
	float hyp = sqrt(xPos*xPos + yPos * yPos);
	xPos /= hyp;
	yPos /= hyp;
	if (hyp <= 4000) {
		/*if (collide == true && xPos < 0) {
			fDirection.x += 2.5;
			fDirection.y = 0;
			collide = false;
		}
		if (collide == true && xPos > 0) {
			fDirection.x -= 2.5;
			fDirection.y = 0;
			collide = false;
		}*/
		
		fDirection.x += xPos*speedMult;
		fDirection.y += yPos*speedMult;
		eSprite.setTexture(attack);
	}else {
		eSprite.setTexture(idle);
	}
	return fDirection;
}

void enemy::respawn(sf::Sprite &theSprite, sf::Vector2f posToGo) {
	theSprite.setPosition(posToGo);
	eHealth = 100;
	mult += 1;
	eHealth += mult*2;
}

string enemy::healthText() {
	string healthToDisplay;
	healthToDisplay = std::to_string(eHealth);
	return healthToDisplay;
}
