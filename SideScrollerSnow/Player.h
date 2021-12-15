#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Player
{
private:
	//Variables
	float x = 0;
	float y = 0;

	float velocityX = 0;
	float velocityY = 0;
	float accelerationX = 0;
	float accelerationY = 0;

	float gravity = 2;

	//Game objects
	unique_ptr<RectangleShape> shape;

	//private functions

public:
	//Variables

	//Constructors
	Player();
	~Player();

	//Functions
	void controls();
	void updateMovement();
	Shape& getShape();
};

