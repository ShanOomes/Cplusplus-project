#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <vector>

#include "Player.h"
#include "Flake.h"
#include "Obstacle.h"

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

	vector<Obstacle*> obstacle;
	float spawnTimer;
	float spawnTimerMax;
	int maxObstacles;

	//Window
	RenderWindow* window;
	VideoMode videoMode;
	Event ev;

	//Game objects

	//Private functions
	void initVariables();
	void initWindow();
	void initShapes();
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