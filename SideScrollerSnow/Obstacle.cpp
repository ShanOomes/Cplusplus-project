#include "Obstacle.h"

void Obstacle::initVariables()
{
	//speed = static_cast<float>(3);

	speed = 0.f;
}

void Obstacle::initTexture()
{
	if (!texture.loadFromFile("Textures/tree.png")) {
		cout << "Error with tree texture loading" << endl;
	}
}

void Obstacle::initSprite()
{
	sprite.setTexture(texture);

	sprite.setScale(Vector2f(0.15f, 0.15f));
}

Obstacle::Obstacle(float pos_x, float pos_y)
{
	initVariables();

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

Vector2f Obstacle::getPos()
{
	return sprite.getPosition();
}

void Obstacle::IncreaseSpeed(float value)
{
	speed = value;
}

void Obstacle::update()
{
	sprite.move(-speed, 0.f);
}

void Obstacle::draw(RenderWindow* window)
{
	window->draw(sprite);
}


