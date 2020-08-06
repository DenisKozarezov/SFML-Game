#include "Game.h"

Game::Game()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1900, 900), "My Game");
	this->window->setFramerateLimit(120);

	DrawableContainer::initialize(5);

	this->gui = GUI::get_instance();
	this->camera = new Camera;
	this->time = new sf::Time;
	this->clock = new sf::Clock;
	this->player = new Player;
	this->isActive = new bool(true);

	Player::set_main_player(this->player);

	Warrior* warrior1 = new Warrior(Vector2(500, 200));
	this->player->set_main_character(warrior1);

	this->gui->initialize();
}
Game::~Game()
{
	delete this->clock;

	delete this->player;

	delete this->time;
	delete this->camera;
	delete this->isActive;
	delete this->window;
}

void Game::run()
{		
	while (this->window->isOpen())
	{		
		input_update();
		graphics_update();

		this->clock->restart();
	}
}
void Game::input_update()
{
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->window->close();
			this->gui->input_update(event);
		}
	}
	
	if (this->window->hasFocus())
	{
		this->camera->input_update(*this->window);
		this->player->input_update(event);
	}
}
void Game::graphics_update()
{
	this->window->clear();

	DrawableContainer::update(*this->window);	

	this->gui->graphics_update(*this->window);

	this->window->display();
}
