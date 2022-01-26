#include "Obstacle.h"

void Obstacle::initVariables()
{
	speed = static_cast<float>(3);
}

void Obstacle::initShape()
{
	sprite.setScale(Vector2f(0.15f, 0.15f));
}

void Obstacle::initTexture()
{
	if (!texture.loadFromFile("Textures/tree.png")) {
		cout << "Error with tree sprite loading" << endl;
	}
}

void Obstacle::initSprite()
{
	sprite.setTexture(texture);
}

Obstacle::Obstacle(float pos_x, float pos_y)
{
	initVariables();
	initShape();

	initTexture();
	initSprite();

	sprite.setPosition(pos_x, pos_y);
}

Obstacle::~Obstacle()
{
}

const FloatRect Obstacle::getBounds() const
{
	return sprite.getGlobalBounds();
}

Sprite Obstacle::getRect()
{
	return sprite;
}

void Obstacle::update()
{
	sprite.move(-speed, 0.f);
}

void Obstacle::draw(RenderWindow* window)
{
	window->draw(sprite);
}


