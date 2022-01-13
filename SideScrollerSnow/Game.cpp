#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->window = nullptr;

	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxObstacles = 10;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new RenderWindow(this->videoMode, "Game 1", Style::Titlebar | Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initShapes()
{
}

//Constructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initShapes();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

//Functions
void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->ev.key.code == Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
	//this->debugGame();

	this->player.update();

	this->spawnObstacles();

	this->flake.update();
}

void Game::render()
{
	this->window->clear();

	//Draw potential objects
	this->player.draw(this->window);
	this->flake.draw(this->window);

	for (auto* obstacle : this->obstacle)
	{
		obstacle->draw(this->window);
	}

	this->window->display();
}

void Game::spawnObstacles()
{
	this->spawnTimer += 0.1f;
	if (this->spawnTimer >= this->spawnTimerMax)
	{
		this->obstacle.push_back(new Obstacle(this->window->getSize().x, 500.f));
		this->spawnTimer = 0.f;
	}

	for (int i = 0; i < this->obstacle.size(); ++i)
	{
		//Update the movement of the obstacle
		this->obstacle[i]->update();

		//Remove enemy if off screen
		if (this->obstacle[i]->getBounds().left > this->window->getSize().x) {
			this->obstacle.erase(this->obstacle.begin() + i);
		}
	}
}

void Game::debugGame()
{
	cout << "Mouse pos: " << Mouse::getPosition(*this->window).x << " " << Mouse::getPosition(*this->window).y << "\n";
}