#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->player.setWindow(600, 800);
	this->window = new RenderWindow(this->videoMode, "Game 1", Style::Titlebar | Style::Close);

	this->window->setFramerateLimit(120);
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

	this->player.move();
}

void Game::render()
{
	this->window->clear();

	//Draw potential objects

	this->window->draw(player.getShape());
	this->window->display();
}

void Game::debugGame()
{
	cout << "Mouse pos: " << Mouse::getPosition(*this->window).x << " " << Mouse::getPosition(*this->window).y << "\n";
}