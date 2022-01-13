#include "Obstacle.h"

void Obstacle::initVariables()
{
	speed = static_cast<float>(3);
}

void Obstacle::initShape()
{
	obstacle.setSize(Vector2f(25.f, 50.f));
	//Color color(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1);
	obstacle.setFillColor(Color::White);

}

Obstacle::Obstacle(float pos_x, float pos_y)
{
	initVariables();
	initShape();

	obstacle.setPosition(pos_x, pos_y);
}

Obstacle::~Obstacle()
{
}

const FloatRect Obstacle::getBounds() const
{
	return obstacle.getGlobalBounds();
}

RectangleShape Obstacle::getRect()
{
	return obstacle;
}

void Obstacle::update()
{
	obstacle.move(-speed, 0.f);
}

void Obstacle::draw(RenderWindow* window)
{
	window->draw(obstacle);
}


