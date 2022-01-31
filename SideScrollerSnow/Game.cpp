#include "Game.h"

//Private functions
void Game::initVariables()
{
	this->window = nullptr;

	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxObstacles = 10;
	this->isGameOver = false;

	this->score = 0;
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
	this->gameOverText.setFont(poxelFont);
	this->gameOverText.setString("Game Over!");

	this->gameOverText.setOrigin(this->gameOverText.getGlobalBounds().left + round(this->gameOverText.getGlobalBounds().width / 2), this->gameOverText.getGlobalBounds().top + round(this->gameOverText.getGlobalBounds().height / 2));
	this->gameOverText.setPosition(250, 250);
		
	// set the character size
	this->gameOverText.setCharacterSize(80); // in pixels, not points!

	// set the color
	this->gameOverText.setFillColor(Color::White);

	// set the text style
	this->gameOverText.setStyle(Text::Bold);

	this->scoreText.setFont(poxelFont);
	this->scoreText.setString("00");
	this->scoreText.setOrigin(this->scoreText.getGlobalBounds().left + round(this->scoreText.getGlobalBounds().width / 2), this->scoreText.getGlobalBounds().top + round(this->scoreText.getGlobalBounds().height / 2));
	this->scoreText.setPosition(730, 20);
	this->scoreText.setCharacterSize(60);
	this->scoreText.setFillColor(Color::White);

}

void Game::initFonts()
{
	if (!poxelFont.loadFromFile("Fonts/poxel.ttf")) {
		cout << "Error with font loading" << endl;
	}
	if (!pixelManiaFont.loadFromFile("Fonts/Pixelmania.ttf")) {
		cout << "Error with font loading" << endl;
	}
}

void Game::updateText()
{
	this->scoreText.setString(to_string(score));
}

void Game::incrementScore()
{
	if (obstacles.size() > 0 && (*curr)->getPos().x < player.getPos().x)
	{
		cout << "Incrementing score" << endl;
		if(next(curr, 1) != obstacles.end()){
			curr = next(curr, 1);
			score++;
		}
	}
}

double Game::concat()
{
	string random = to_string(rand() % 10 + 1);
	string num = "0.0";

	// Concatenate both strings
	string allTogether = num.substr(0, num.find_first_of(".") + 2) + random;

	// Convert the concatenated string
	// to integer
	double c = stod(allTogether);

	// return the formed integer
	return c;
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

		this->updateText();

		incrementScore();
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

	this->window->draw(this->scoreText);

	for (auto* obstacle : this->obstacles)
	{
		obstacle->draw(this->window);
	}

	this->window->display();
}

void Game::spawnObstacles()
{
	spawnTimer += concat();
	if (spawnTimer >= spawnTimerMax)
	{
		Obstacle* ob = new Obstacle(window->getSize().x, 470.f);
		obstacles.push_back(ob);
		
		curr = obstacles.begin();

		spawnTimer = 0.f;
	}

	for (int i = 0; i < obstacles.size(); ++i)
	{
		//Update the movement of the obstacle
		obstacles[i]->update();

		//Remove obstacle if off screen
		
		if (obstacles[i]->getPos().x < -10) {
			delete obstacles[i];
			curr = obstacles.erase(obstacles.begin() + i);
			cout << "Obstacle delete" << endl;
		}
	}
}

void Game::checkCollision()
{
	for (int i = 0; i < this->obstacles.size(); ++i)
	{
		const bool collides = this->player.getRect().getGlobalBounds().intersects(this->obstacles[i]->getRect().getGlobalBounds());
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