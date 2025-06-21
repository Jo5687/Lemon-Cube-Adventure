#include "pch.h"
#include <iostream>
#include <string>
#include <random>
#include "player.h"
#include "tile.h"
#include "bullet.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "enemy.h"
#include "ui.h"
#include "title.h"
#include <fstream>
using namespace std;

int main()
{
#pragma region Variables
	enum states {titleScreen, generation, game, deathScreen};
	states gameState = titleScreen; 
	bool up = false;
	bool down = false;
	bool right = false;
	bool left = false;
	const int mapSize = 25;
	int variationLvl = 2;
	int ammoCount = 0;
	int aim = 0;
	sf::Vector2f projectileD [6];
	int bulletSpeed = 7;
	bool eCollide = false;
	ui mainUI;
	vector < sf::Vector2f > positions;
	int vSize = 0;
	float moveSpeed = 2.5;
	float CmoveSpeed = 2.5;
	bool startGame = false;
	fstream saveScore; 
	int highScore = 0;
	int currentScore = 0;
	float spdInc = .05f;
	float mapGen = 256;
	int UIcount = 5;
#pragma endregion
#pragma region Sprites
	//textures
	sf::Texture collideTex;
	collideTex.loadFromFile("Sprites/collider.png");
	sf::Texture wall;
	wall.loadFromFile("Sprites/wall.png");
	sf::Texture ceiling; 
	ceiling.loadFromFile("Sprites/ceiling.png");

	//sprites
	bullet b;
	sf::Sprite bulletSpriteMain;
	bulletSpriteMain.setTexture(b.bTex);
	bulletSpriteMain.setScale(8, 8);
	bulletSpriteMain.setOrigin(4, -4);
	bulletSpriteMain.setPosition(-128, -128);
	sf::Sprite mainSprite;
	mainSprite.setOrigin(12, 13.5);
	mainSprite.setScale(8, 8);
	mainSprite.setPosition(128, 128);
	sf::Sprite collider;
	collider.setTexture(collideTex);
	collider.setScale(7, 8);
	collider.setPosition(128, 128);
	collider.setOrigin(12, -8);
	sf::Sprite enemyS;
	sf::Sprite wallS;
	wallS.setTexture(wall);
	wallS.setPosition(5, 0);
	sf::Sprite wall2;
	wall2.setTexture(wall);
	wall2.setPosition(6401, 0);
	sf::Sprite ceilingS;
	ceilingS.setTexture(ceiling);
	ceilingS.setPosition(0, 5);
	sf::Sprite floorS;
	floorS.setTexture(ceiling);
	floorS.setPosition(0, 6401);
	sf::Sprite bounds[4] = { wallS, wall2, floorS, ceilingS };
#pragma endregion;
#pragma region Initialization
	//potential array to hold stock of "bullets"
	sf::Sprite bulletArray[5] = { bulletSpriteMain, bulletSpriteMain, bulletSpriteMain, bulletSpriteMain, bulletSpriteMain};
	int weapon = 5;
	int xpFlow = 0;
	player thePlayer(100, 1, xpFlow, 10);

	//window
	sf::RenderWindow mainWindow(sf::VideoMode(1280, 720), "LCube");
	//sf::View camera(sf::Vector2f(910, 510), sf::Vector2f(1792, 1008));
	sf::View camera(sf::Vector2f(910, 510), sf::Vector2f(1920, 1080));
	//sf::View camera(sf::Vector2f(4480, 4480), sf::Vector2f(8960, 8960));
	
	random_device rd;
	tile tileClass;
	int grassType;
	int whichType = 0;
	sf::Sprite tiles[mapSize][mapSize];
	sf::Sprite grass[mapSize][mapSize];
	enemy theEnemy(100, 20);
	title mainScreen;
	
#pragma endregion
	//inWindow
	while (mainWindow.isOpen())
	{
#pragma region More Variables
		sf::Event event;
		sf::Vector2f posBefore = mainSprite.getPosition();
		sf::Vector2f pBC = collider.getPosition();
		sf::Vector2f posBCol = camera.getCenter();
		sf::Vector2f(move);
		sf::Vector2f(Cmove);
#pragma endregion
		while (mainWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				mainWindow.close();
			}
#pragma region Input
			if (event.type == event.KeyPressed) {
				if (event.key.code == sf::Keyboard::Escape) {
					mainWindow.close();
				}
				if (event.key.code == sf::Keyboard::W) {
					if (thePlayer.pHealth > 20) {
						mainSprite.setTexture(thePlayer.up);
					}
					else {
						mainSprite.setTexture(thePlayer.upH);
					}
					up = true;
					aim = 1;
				}
				if (event.key.code == sf::Keyboard::S) {
					if (thePlayer.pHealth > 20) {
						mainSprite.setTexture(thePlayer.idle);
					}
					else {
						mainSprite.setTexture(thePlayer.idleH);
					}
					down = true;
					aim = 0;
				}
				if (event.key.code == sf::Keyboard::A) {
					if (thePlayer.pHealth > 20) {
						mainSprite.setTexture(thePlayer.left);
					}
					else {
						mainSprite.setTexture(thePlayer.leftH);
					}
					left = true;	
					aim = 2;
				}
				if (event.key.code == sf::Keyboard::D) {
					if (thePlayer.pHealth > 20) {
						mainSprite.setTexture(thePlayer.right);
					}
					else {
						mainSprite.setTexture(thePlayer.rightH);
					}
					right = true;		
					aim = 3;
				}
				if (event.key.code == sf::Keyboard::Z) {
					startGame = true;
				}
				//shoot input
				if (event.key.code == sf::Keyboard::Space) {
					if (thePlayer.pHealth > 20) {
						mainSprite.setTexture(thePlayer.shoot);
					}
					else {
						mainSprite.setTexture(thePlayer.shootH);
					}
					//getting class constructor
					bulletArray[ammoCount].setPosition(posBefore);
						if(aim == 0) {
							projectileD[ammoCount].y += 1 *bulletSpeed;							
						}
						if (aim == 1) {
							projectileD[ammoCount].y -= 1 * bulletSpeed;
						}
						if (aim == 2) {
							projectileD[ammoCount].x -= 1 * bulletSpeed;
						}
						if (aim == 3) {
							projectileD[ammoCount].x += 1 * bulletSpeed;
						}
					ammoCount += 1;
					UIcount -= 1;
					if (ammoCount > 5) {
						ammoCount = 0;
						UIcount = 5;
						if (thePlayer.pHealth > 20) {
							mainSprite.setTexture(thePlayer.reload);
						}
						else {
							mainSprite.setTexture(thePlayer.reloadH);
						}
						//resetBullets
						for (int resetB = 0; resetB < 5; resetB++) {
							bulletArray[resetB].setPosition(0, -300);
							projectileD[resetB].x = 0;
							projectileD[resetB].y = 0;
						}
					}					
				}
				if (event.key.code == sf::Keyboard::R) {
					ammoCount = 0;
					UIcount = 5;
					if (thePlayer.pHealth > 20) {
						mainSprite.setTexture(thePlayer.reload);
					}
					else {
						mainSprite.setTexture(thePlayer.reloadH);
					}
					//resetBullets
					for (int resetB = 0; resetB < 5; resetB++) {
						bulletArray[resetB].setPosition(0, -300);
						projectileD[resetB].x = 0;
						projectileD[resetB].y = 0;
					}
				}
			}
			if (event.type == event.KeyReleased) {
				if (event.key.code == sf::Keyboard::W) {
					up = false;
				}
				if (event.key.code == sf::Keyboard::S) {
					down = false;
				}
				if (event.key.code == sf::Keyboard::A) {
					left = false;
				}
				if (event.key.code == sf::Keyboard::D) {
					right = false;
				}
				if (event.key.code == sf::Keyboard::Z) {
					startGame = false;
				}
			}
#pragma endregion
		}
		//The actual game
		switch (gameState) {
#pragma region Title
			case titleScreen:
				//ensure Camera Position
				camera.setCenter(910, 510);
				//Display High Score
				saveScore.open("highscore.txt", ios::in);
				saveScore >> highScore;
				saveScore.close();
				//Drawing
				mainWindow.clear();
				mainWindow.draw(mainScreen.mainT);
				mainScreen.highScore.setString("High Score: " + mainScreen.gettingScore(highScore));
				mainWindow.draw(mainScreen.highScore);
				//State change
				if (startGame == true) {
					gameState = generation;
				}
				break;
#pragma endregion
#pragma region MapGeneration
			case generation:
				/*cout << "Enter Variation Level ";
				cin >> variationLvl;*/
				//Obstacles
				for (int x = 1; x < mapSize; ++x) {
					for (int y = 0; y < mapSize; ++y) {
						//randomizer
						whichType = rd() % variationLvl;
						if (whichType == 1) {
							tiles[x][y].setTexture(tileClass.rock);
							tiles[x][y].setScale(8, 8);
							tiles[x][y].setPosition((mapGen * x), (mapGen * y));
						}
						if (whichType == 2) {
							tiles[x][y].setTexture(tileClass.water);
							tiles[x][y].setScale(8, 8);
							tiles[x][y].setPosition((mapGen * x), (mapGen * y));
						}
						if (whichType == 3) {
							tiles[x][y].setTexture(tileClass.tree);
							tiles[x][y].setScale(8, 8);
							tiles[x][y].setPosition((mapGen * x), (mapGen * y));
						}
					}
				}
				cout << "Map Size " << mapSize << " x " << mapSize << endl;
				cout << "Variation Level " << variationLvl << endl;
				//GrassArray
				for (int x = 0; x < mapSize; ++x) {
					for (int y = 0; y < mapSize; ++y) {
						grassType = rd() % 6;
						if (grassType == 0 || 4) {
							grass[x][y].setTexture(tileClass.grass);
							grass[x][y].setScale(8, 8);
							grass[x][y].setPosition((mapGen * x), (mapGen * y));
						}
						if (grassType == 1) {
							grass[x][y].setTexture(tileClass.flowers);
							grass[x][y].setScale(8, 8);
							grass[x][y].setPosition((mapGen * x), (mapGen * y));
						}
						if (grassType == 2) {
							grass[x][y].setTexture(tileClass.grass2);
							grass[x][y].setScale(8, 8);
							grass[x][y].setPosition((mapGen * x), (mapGen * y));
						}
						if (grassType == 3) {
							grass[x][y].setTexture(tileClass.flowers2);
							grass[x][y].setScale(8, 8);
							grass[x][y].setPosition((mapGen * x), (mapGen * y));
							positions.push_back(grass[x][y].getPosition());
							vSize += 1;
						}
					}
				}
				//Initializing Enemy
				enemyS = theEnemy.spawn();
				mainSprite.setTexture(thePlayer.idle);
				gameState = game;
				break;
#pragma endregion
#pragma region Game
			case game:
				//player Killed
				if (thePlayer.pHealth <= 0) {
					gameState = deathScreen;
				}
				//enemy Killed
				if (theEnemy.eHealth <= 0) {
					thePlayer.pXP += 25;
					theEnemy.respawn(enemyS, positions[rd() % vSize]);
					if (eCollide == true) {
						theEnemy.respawn(enemyS, positions[rd() % vSize]);
					}
					thePlayer.pLevel += 1;
					thePlayer.pHealth += 5;
					thePlayer.pDamage += 5;
					moveSpeed += spdInc;
					CmoveSpeed += spdInc;
					theEnemy.speedMult += .05;
				}
				mainWindow.setView(camera);
				//moveCode
				if (up == true) {
					move.y -= moveSpeed;				
				}
				if (down == true) {
					move.y += moveSpeed;					
				}
				if (left == true) {
					move.x -= moveSpeed;					
				}
				if (right == true) {
					move.x += moveSpeed;
				}
				//camera Bounds + Movement
				if (posBefore.y > 530 && posBefore.y < 5845) {
					if (up == true) {
						Cmove.y -= CmoveSpeed;
					}
					if (down == true) {
						Cmove.y += CmoveSpeed;
					}
				}
				if (posBefore.x > 910 && posBefore.x < 5500) {
					if (left == true) {
						Cmove.x -= CmoveSpeed;
					}
					if (right == true) {
						Cmove.x += CmoveSpeed;
					}
				}
				//general Movement
				mainSprite.move(move);
				collider.move(move);
				camera.move(Cmove);
				enemyS.move(theEnemy.follow(posBefore, enemyS, eCollide));
				mainWindow.clear();
				//collisions
				for (int x1 = 0; x1 < mapSize; x1++) {
					for (int y1 = 0; y1 < mapSize; y1++) {
						mainWindow.draw(grass[x1][y1]);
						mainWindow.draw(tiles[x1][y1]);
						if (collider.getGlobalBounds().intersects(tiles[x1][y1].getGlobalBounds())) {
							collider.setPosition(pBC);
							camera.setCenter(posBCol);
							mainSprite.setPosition(posBefore);
						}
						if (enemyS.getGlobalBounds().intersects(tiles[x1][y1].getGlobalBounds())) {
							eCollide = true;
							//enemyS.setPosition(theEnemy.ePos);
							enemyS.setTexture(theEnemy.fly);
						}
						if (enemyS.getGlobalBounds().intersects(collider.getGlobalBounds())) {
							theEnemy.respawn(enemyS, positions[rd() % vSize]);
							if (eCollide == true) {
								theEnemy.respawn(enemyS, positions[rd() % vSize]);
							}
							thePlayer.pHealth -= theEnemy.eDamage;
							mainSprite.setTexture(thePlayer.hurt);
						}
					}
				}
				for (int x3 = 0; x3 < 4; x3++) {
					if (collider.getGlobalBounds().intersects(bounds[x3].getGlobalBounds())) {
						collider.setPosition(pBC);
						camera.setCenter(posBCol);
						mainSprite.setPosition(posBefore);
					}
				}
				mainWindow.draw(enemyS);
				mainWindow.draw(mainSprite);
				//bullet Management
				for (int b = 0; b < 5; b++) {
					bulletArray[b].move(projectileD[b]);
					mainWindow.draw(bulletArray[b]);
					if (enemyS.getGlobalBounds().intersects(bulletArray[b].getGlobalBounds())) {
						theEnemy.eHealth -= 10;
						enemyS.setTexture(theEnemy.hit);
						bulletArray[b].setPosition(-1000, -1000);
					}
				}
#pragma region UI
				mainUI.enemyHealth.setPosition(enemyS.getPosition());
				mainUI.playerHealth.setPosition(posBefore);
				mainUI.playerLevel.setPosition(posBCol);
				mainUI.uiSprite.setPosition(posBCol);
				mainUI.ball.setPosition(posBCol);
				mainUI.bC.setPosition(posBCol);
				mainUI.playerHealth.setString(thePlayer.pHealthText());
				mainUI.enemyHealth.setString(theEnemy.healthText());
				mainUI.playerLevel.setString(thePlayer.pLevelText());
				mainUI.bC.setString(mainUI.ballCount(UIcount));
				mainWindow.draw(mainUI.uiSprite);
				mainWindow.draw(mainUI.enemyHealth);
				mainWindow.draw(mainUI.playerHealth);
				mainWindow.draw(mainUI.playerLevel);
				mainWindow.draw(mainUI.ball);
				mainWindow.draw(mainUI.bC);
#pragma endregion
				currentScore = thePlayer.pLevel*100;
				break;
#pragma endregion
#pragma region End
			case deathScreen:
				//drawing UI
				mainWindow.clear();
				mainWindow.draw(mainUI.Hs);
				mainWindow.draw(mainScreen.mainT);
				mainScreen.mainT.setString("Game Over, Press Escape to Quit");
				mainUI.Hs.setString("Score: " + mainUI.score(thePlayer.pLevel));
				mainUI.Hs.setPosition(posBCol);
				mainScreen.mainT.setPosition(posBCol);
				mainScreen.mainT.setOrigin(450, 50);
#pragma endregion
#pragma region Scoring
				//get High Score
				saveScore.open("highscore.txt", ios::in);
				saveScore >> highScore;
				saveScore.close();
				//save Score for the Session
				saveScore.open("score.txt", ios::out);
				saveScore << currentScore;
				saveScore.close();
				//New high score 
				if (currentScore > highScore) {
					saveScore.open("highscore.txt", ios::out);
					saveScore << currentScore;
					saveScore.close();
				}
#pragma endregion
				break;
		}
		mainWindow.display();
		mainWindow.setFramerateLimit(240);
	}
	std::cout << "Thank you for playing!"
		<< endl;
}