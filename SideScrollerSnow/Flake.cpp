#include "Flake.h"

Flake::Flake()
{
	this->snowflakes.reserve(numOfSnowflakes);
}

Flake::~Flake()
{
}

// Create a snowflake and store it in an array
void Flake::createFlake(vector<CircleShape>& arr)
{
	CircleShape flake(float(rand()) / (float)(RAND_MAX / 3.0f) + 0.5f);
	flake.setPosition(float(rand() % this->WIDTH), 0.0f);
	flake.setFillColor(Color::White);

	arr.emplace_back(flake);
}

void Flake::update()
{
	this->elapsed++;

	// If the delay has passed and the max num of snowflakes isn't reached, create another
	if (this->elapsed >= this->delay && this->snowflakes.size() < this->numOfSnowflakes)
	{
		createFlake(this->snowflakes);
		this->elapsed = 0;
	}
}

void Flake::draw(RenderWindow* window)
{
	for (unsigned int i = 0; i < snowflakes.size(); i++)
	{
		snowflakes[i].move(0.0f, snowflakes[i].getRadius() * 0.4f);
		window->draw(snowflakes[i]);

		// Don't draw snowflakes that are outside of the window
		if (snowflakes[i].getPosition().y >= HEIGHT)
		{
			snowflakes.erase(snowflakes.begin() + i);
		}
	}
}
