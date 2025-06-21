#include "pch.h"
#include "player.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

player::player(int health, int level, int xp, int damage){
	pHealth = health;
	pLevel = level;
	pXP = xp;
	pDamage = damage;
	idle.loadFromFile("Sprites/LCubeDown.png");
	up.loadFromFile("Sprites/LCubeUp.png");
	right.loadFromFile("Sprites/LCubeRight.png");
	left.loadFromFile("Sprites/LCubeLeft.png");
	idleH.loadFromFile("Sprites/LCubeDownH.png");
	upH.loadFromFile("Sprites/LCubeUpH.png");
	rightH.loadFromFile("Sprites/LCubeRightH.png");
	leftH.loadFromFile("Sprites/LCubeLeftH.png");
	shoot.loadFromFile("Sprites/LCubeShoot.png");
	shootH.loadFromFile("Sprites/LCubeShootH.png");
	reload.loadFromFile("Sprites/LCubeReload.png");
	reloadH.loadFromFile("Sprites/LCubeReloadH.png");
	hurt.loadFromFile("Sprites/LCubeHurt.png");
}

string player::pHealthText() {
	string pDisplay;
	pDisplay = std::to_string(pHealth);
	return pDisplay;
}

string player::pLevelText() {
	string lDisplay;
	lDisplay = std::to_string(pLevel);
	return lDisplay;
}

void player::die() {
	//??? never used
}
