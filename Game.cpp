#include "Game.h"
#include <iostream>

sf::Clock *Game::clock = new sf::Clock;
Game::Game()
{
	this->initialize();
	GameDrawableContainer::initialize();
}
Game::~Game()
{
	delete this->window;
	delete this->clock;
}

void Game::initialize()
{
	this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "My Game");
}
void Game::run()
{		
	while (this->window->isOpen())
	{		
		update_input();
		update_graphics();	
	}
}
void Game::update_graphics()
{
	this->window->clear();
	GameDrawableContainer::update(*Game::window);	
	this->window->display();
}
void Game::update_input()
{
	sf::Event event;
	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->window->close();
		}
	}
}

const sf::Clock* Game::get_clock()
{
	return clock;
}
