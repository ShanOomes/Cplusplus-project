#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

using namespace std;
using namespace sf;

class Player
{
private:

	//create player shape
	std::unique_ptr<sf::RectangleShape> shape;
public:
	unsigned window_width = 0;
	unsigned window_height = 0;

	~Player();
	void move();
	void setWindow(int height, int width);
	Shape& getShape();
};

