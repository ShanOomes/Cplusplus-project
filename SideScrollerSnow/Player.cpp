#include "Player.h"

Player::Player()
{
	//set te shape position and the color of the object
	shape = make_unique<RectangleShape>(RectangleShape(Vector2f(40.0f, 40.0f)));
	shape->setPosition(Vector2f(35.0f, 100.0f));
	shape->setFillColor(Color::White);
}

Player::~Player()
{
}

void Player::controls()
{
	//Player controls
	if (Keyboard::isKeyPressed(Keyboard::Key::Space) && isGrounded) {
		velocityY = -15;
	}
}

void Player::update()
{	
	controls();

	Vector2f position = getPos();
	if (position.y <= 500)
	{
		velocityY += gravity;
		isGrounded = false;
	}
	else if (position.y > 500)
	{
		//cout << "Going under the ground" << endl;
		isGrounded = true;
		setPos(position.x, 500);
		velocityY = 0;
	}

	velocityX += accelerationX;
	velocityY += accelerationY;

	setPos(getPos().x + velocityX, getPos().y + velocityY);
}

void Player::setPos(float x, float y)//Set position of shape
{
	shape->setPosition(x, y);
}

void Player::draw(RenderWindow* window)//Draw shape to window
{
	window->draw(*shape);
}

Vector2f Player::getPos()//Returns position of shape
{
	return shape->getPosition();
}

RectangleShape Player::getRect()
{
	return *shape;
}

