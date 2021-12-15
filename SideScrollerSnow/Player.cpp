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

void Player::controls()
{
	//Player controls
	if (Keyboard::isKeyPressed(Keyboard::Key::Space)) {
		this->velocityY = -15;
	}
}

void Player::updateMovement()
{
	if (y < 500)                  //If you are above ground
		velocityY += gravity;    //Add gravity
	else if (y > 500)             //If you are below ground
		y = 500;                 //That's not supposed to happen, put him back up

	velocityX += accelerationX;
	velocityY += accelerationY;

	x += velocityX;
	y += velocityY;
}

Shape& Player::getShape()
{
	return*shape;
}