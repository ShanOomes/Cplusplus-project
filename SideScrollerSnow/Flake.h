#pragma once
#include <iostream>
#include <vector>
#include <random>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Flake
{
private:
	//Variables
	unsigned int elapsed = 0;

	unsigned int numOfSnowflakes = 200;
	unsigned int delay = 10;

	const unsigned int WIDTH = 800;
	const unsigned int HEIGHT = 600;

	//Game objects
	vector<CircleShape> snowflakes;

	//private functions

public:
	//Variables

	//Constructors
	Flake();
	~Flake();

	//Functions
	void update();
	void draw(RenderWindow* window);
	void createFlake();

};

