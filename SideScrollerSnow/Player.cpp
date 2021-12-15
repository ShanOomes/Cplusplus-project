#include "Player.h"

Player::Player()
{
	//set te shape position and the color of the object
	shape = make_unique<RectangleShape>(RectangleShape(Vector2f(40.0f, 40.0f)));
	shape->setPosition(Vector2f(0.0f, 100.0f));
	shape->setFillColor(Color::White);
}

Player::~Player()
{
}

void Player::move()
{
	//have the player move with WASD keys.
	if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
		shape->move(0.0f, -0.1f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
		shape->move(-0.1f, 0.0f);

	}
	if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
		shape->move(0.0f, 0.1f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
		shape->move(0.1f, 0.0f);
	}

	//screen collison

	//left collison
	if (shape->getPosition().x < 0.f)
		shape->setPosition(0.f, shape->getPosition().y);
	//top collison
	if (shape->getPosition().y < 0.f)
		shape->setPosition(shape->getPosition().x, 0.f);
	//rignt collison
	if (shape->getPosition().x + shape->getGlobalBounds().width > window_width)
		shape->setPosition(window_width - shape->getGlobalBounds().width, shape->getPosition().y);
	//bottom collison
	if (shape->getPosition().y + shape->getGlobalBounds().height > window_height)
		shape->setPosition(shape->getPosition().x, window_height - shape->getGlobalBounds().height);
}

void Player::setWindow(int height, int width)
{
	this->window_height = height;
	this->window_width = width;
}

sf::Shape& Player::getShape()
{
	return*shape;
}