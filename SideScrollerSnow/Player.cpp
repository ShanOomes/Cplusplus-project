#include "Player.h"

Player::Player()
{
	initTexture();
	initSprite();
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

void Player::initTexture()
{
	if (!texture.loadFromFile("Textures/stick-figure-pixel.png")) {
		cout << "Error with player texture loading" << endl;
	}
}

void Player::initSprite()
{
	sprite.setTexture(texture);
	sprite.setScale(Vector2f(0.8f, 0.8f));

	sprite.setPosition(100, 0);
}

void Player::update()
{	
	controls();

	Vector2f position = getPos();
	if (position.y <= 460)
	{
		velocityY += gravity;
		isGrounded = false;
	}
	else if (position.y > 460)
	{
		//cout << "Going under the ground" << endl;
		isGrounded = true;
		setPos(position.x, 460);
		velocityY = 0;
	}

	velocityX += accelerationX;
	velocityY += accelerationY;

	setPos(getPos().x + velocityX, getPos().y + velocityY);
}

void Player::setPos(float x, float y)//Set position of shape
{
	sprite.setPosition(x, y);
}

void Player::draw(RenderWindow* window)//Draw shape to window
{
	window->draw(sprite);
}

Vector2f Player::getPos()//Returns position of shape
{
	return sprite.getPosition();
}

Sprite Player::getRect()
{
	return sprite;
}

