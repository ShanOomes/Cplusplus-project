#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <stdlib.h>

#include "Player.h"
#include "Flake.h"
#include "Obstacle.h"
#include "Environment.h"

using namespace std;
using namespace sf;
/*
	Class that acts as the game engine.
*/
class Game
{
private:
	//Variables
	Player player;
	Flake flake;

	Environment environment;

	bool isGameOver;

	vector<Obstacle*> obstacles;

	vector<Obstacle*>::iterator curr;
	float obstacleSpeed;

	float spawnTimer;
	float spawnTimerMax;
	int maxObstacles;

	Text scoreText;
	int score;
	bool functionCalled;

	Font poxelFont;
	Font pixelManiaFont;

	Text gameOverText;

	//Window
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;

	//Game objects

	//Private functions
	void initVariables();
	void initWindow();
	void initShapes();
	void initFonts();
	void initText();

	void updateText();
	void incrementScore();
public:
	//Constructors
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();
	void update();
	void render();

	void spawnObstacles();
	void checkCollision();

	void debugGame();
};