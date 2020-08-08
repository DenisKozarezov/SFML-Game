#include "Game.h"

sf::RenderWindow* Game::window = 0;
Game::Game()
{
	this->event = new sf::Event;
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "SFML-Game", sf::Style::Fullscreen);
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
	this->event = new sf::Event;

	while (this->window->pollEvent(*this->event))
	{
		if (this->event->type == sf::Event::Closed)
		{
			this->window->close();
		}
	}
	
	if (this->window->hasFocus())
	{
		this->camera->input_update(*this->window);
		this->player->input_update(*this->event);

	}

	delete this->event;
}
void Game::graphics_update()
{
	this->window->clear();

	DrawableContainer::update(*this->window);	
	this->gui->update(*this->window, *this->event);

	this->window->display();
}