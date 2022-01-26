#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->window = nullptr;

	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxObstacles = 10;
	this->isGameOver = false;
}

void Game::initWindow()
{
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	this->window = new RenderWindow(this->videoMode, "Snow game", Style::Titlebar | Style::Close);

	this->window->setFramerateLimit(60);
}

void Game::initShapes()
{
}

void Game::initText()
{
	this->gameOverText.setFont(pixelFont);
	this->gameOverText.setString("Game Over!");

	this->gameOverText.setOrigin(this->gameOverText.getGlobalBounds().left + round(this->gameOverText.getGlobalBounds().width / 2), this->gameOverText.getGlobalBounds().top + round(this->gameOverText.getGlobalBounds().height / 2));
	this->gameOverText.setPosition(250, 250);

	//this->gameOverText.setPosition(this->window->getSize().x / 2.0f, this->window->getSize().y / 2.0f);
		
	// set the character size
	this->gameOverText.setCharacterSize(80); // in pixels, not points!

	// set the color
	this->gameOverText.setFillColor(Color::White);

	// set the text style
	this->gameOverText.setStyle(Text::Bold);

}

void Game::initFonts()
{
	if (!pixelFont.loadFromFile("Fonts/poxel.ttf")) {
		cout << "Error with font loading" << endl;
	}
}

//Constructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initShapes();
	this->initFonts();
	this->initText();
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

	if (!this->isGameOver) {
		this->player.update();

		this->spawnObstacles();

		this->checkCollision();

		this->flake.update();
	}
}

void Game::render()
{
	this->window->clear();

	//Draw potential objects
	this->player.draw(this->window);
	this->flake.draw(this->window);

	if (this->isGameOver) {
		this->window->draw(this->gameOverText);
	}

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
		this->obstacle.push_back(new Obstacle(this->window->getSize().x, 470.f));
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

void Game::checkCollision()
{
	for (int i = 0; i < this->obstacle.size(); ++i)
	{
		const bool collides = this->player.getRect().getGlobalBounds().intersects(this->obstacle[i]->getRect().getGlobalBounds());
		if (collides)
		{
			this->isGameOver = true;
			cout << "Collision with obstacles" << endl;
		}
	}
}

void Game::debugGame()
{
	cout << "Mouse pos: " << Mouse::getPosition(*this->window).x << " " << Mouse::getPosition(*this->window).y << "\n";
}