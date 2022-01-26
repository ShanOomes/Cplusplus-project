#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Player
{
private:
	//Variables
	float velocityX = 0;
	float velocityY = 0;
	float accelerationX = 0;
	float accelerationY = 0;

	float gravity = 0.5;

	bool isGrounded;

	//Game objects
	unique_ptr<RectangleShape> shape;

	Sprite sprite;
	Texture texture;

	//private functions
	void controls();

	void initTexture();
	void initSprite();
public:
	//Variables

	//Constructors
	Player();
	~Player();

	//Functions
	void update();
	void setPos(float x, float y);
	void draw(RenderWindow* window);
	Vector2f getPos();
	Sprite getRect();
};

