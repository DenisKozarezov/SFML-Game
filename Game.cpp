#include "Game.h"

sf::RenderWindow* Game::window = 0;
Game *Game::instance = 0;

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
	this->focused = new bool(true);

	Player::set_main_player(this->player);

	Warrior* warrior1 = new Warrior(Vector2(600, 200));
	Warrior* warrior2 = new Warrior(Vector2(800, 150));
	warrior1->set_name("Warrior1");
	warrior2->set_name("Warrior2");
	this->player->set_main_character(warrior1);

	this->gui->initialize();
}

void Game::run()
{		
	while (Game::get_instance()->window->isOpen())
	{		
		Game::get_instance()->input_update();
		Game::get_instance()->graphics_update();
		Collision::check_collision();
		Game::get_instance()->clock->restart();
	}
}
void Game::quit()
{
	window->close();
}
void Game::input_update()
{
	sf::Event event;

	while (this->window->pollEvent(event))
	{
		*this->event = event;
		if (event.type == sf::Event::Closed)
		{
			Game::quit();
		}
	}
	
	if (this->window->hasFocus())
	{
		this->camera->input_update(*this->window);
		this->player->input_update(event);
	}
}
Game* Game::get_instance()
{
	if (!instance) instance = new Game;
	return instance;
}
void Game::graphics_update()
{
	this->window->clear();

	DrawableContainer::update(*this->window);	
	this->gui->update(*this->window, *this->event);

	this->window->display();
}

Game::~Game()
{
	delete this->clock;
	delete this->player;
	delete this->time;
	delete this->camera;
	delete this->focused;
	delete this->window;
	delete this->gui;
	delete this->event;
}