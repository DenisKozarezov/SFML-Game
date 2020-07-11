#include "Game.h"
#include <iostream>

sf::Clock *Game::clock = new sf::Clock;
Game::Game()
{
	this->initialize();
	GameDrawableContainer::initialize();
	Warrior* warrior1 = new Warrior(sf::Vector2f(200, 200));
	warrior1->get_animator()->get_animation("Idle")->set_interval(500);
	Warrior* warrior2 = new Warrior(sf::Vector2f(400, 200));
	warrior2->get_animator()->get_animation("Idle")->set_interval(700);
	Warrior* warrior3 = new Warrior(sf::Vector2f(600, 200));
	warrior3->get_animator()->get_animation("Idle")->set_interval(1000);
	Warrior* warrior4 = new Warrior(sf::Vector2f(800, 200));
	warrior4->get_animator()->get_animation("Idle")->set_interval(1500);
	*warrior4->get_animator()->get_animation("Idle")->isLoop = false;
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
