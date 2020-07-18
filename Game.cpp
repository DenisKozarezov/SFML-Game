#include "Game.h"
#include <iostream>

Game::Game()
{
	this->initialize();
	GameDrawableContainer::initialize();

	Warrior* warrior1 = new Warrior(Vector2(500, 200));
	this->player->set_main_character(warrior1);
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

void Game::initialize()
{
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "My Game");
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
		}
	}
	
	this->camera->input_update(*this->window);
	this->player->input_update(event);	
}
void Game::graphics_update()
{
	this->window->clear();

	GameDrawableContainer::update(*Game::window);	

	this->window->display();
}

