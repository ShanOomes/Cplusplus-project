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

	Sprite sprite;
	Texture texture;

	//private functions
	void initVariables();
	void initTexture();
	void initSprite();
public:
	//Variables

	//Constructors
	Obstacle(float pos_x, float pos_y);
	~Obstacle();

	//Accessors
	const FloatRect getBounds() const;
	Sprite getRect();

	//Functions
	void IncreaseSpeed(float value);
	void update();
	void draw(RenderWindow* window);
	Vector2f getPos();
};

