#include "Obstacle.h"

void Obstacle::initVariables()
{
	this->speed = static_cast<float>(3);
}

void Obstacle::initShape()
{
	this->obstacle.setSize(Vector2f(25.f, 50.f));
	Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
	this->obstacle.setFillColor(color);

}

Obstacle::Obstacle(float pos_x, float pos_y)
{
	this->initVariables();
	this->initShape();

	this->obstacle.setPosition(pos_x, pos_y);
}

Obstacle::~Obstacle()
{
}

const FloatRect Obstacle::getBounds() const
{
	return this->obstacle.getGlobalBounds();
}

void Obstacle::update()
{
	this->obstacle.move(-this->speed, 0.f);
}

void Obstacle::draw(RenderWindow* window)
{
	window->draw(this->obstacle);
}


