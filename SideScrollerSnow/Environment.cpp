#include "Environment.h"

void Environment::initVariables()
{
}

void Environment::initTexture()
{
	if (!texture.loadFromFile("Textures/tree.png")) {
		cout << "Error with tree texture loading" << endl;
	}
}

void Environment::initSprite()
{
	sprite.setTexture(texture);
	sprite.setScale(Vector2f(0.15f, 0.15f));

	shape.setSize(Vector2f(800.f, 100.f));
	shape.setFillColor(Color::White);
	shape.setPosition(0, 540);
}

Environment::Environment()
{
	initVariables();
	initTexture();
	initSprite();
}

Environment::~Environment()
{
}

void Environment::update()
{
}

void Environment::draw(RenderWindow* window)
{
	//window->draw(sprite);
	window->draw(shape);
}
