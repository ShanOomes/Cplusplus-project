#pragma once
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;
class Obstacle
{
private:
	//Variables
	float speed;
	//Game objects
	RectangleShape obstacle;

	//private functions
	void initVariables();
	void initShape();
public:
	//Variables

	//Constructors
	Obstacle(float pos_x, float pos_y);
	~Obstacle();

	//Accessors
	const FloatRect getBounds() const;
	RectangleShape getRect();

	//Functions
	void update();
	void draw(RenderWindow* window);
};

