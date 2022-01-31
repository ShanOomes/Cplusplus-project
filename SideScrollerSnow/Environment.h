#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;
class Environment
{
	//Variables

	//Game objects

	Sprite sprite;
	Texture texture;

	RectangleShape shape;

	//private functions
	void initVariables();
	void initTexture();
	void initSprite();
public:
	//Variables

	//Constructors
	Environment();
	~Environment();

	//Accessors


	//Functions
	void update();
	void draw(RenderWindow* window);
};

