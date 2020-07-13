#include "Game.h"
#include <iostream>

sf::Clock *Game::clock = new sf::Clock;
Camera *Game::camera = new Camera;
Game::Game()
{
	this->initialize();
	GameDrawableContainer::initialize();

	Warrior* warrior1 = new Warrior(Vector2(0, 200));
	warrior1->get_animator()->get_animation("Idle")->set_interval(500);
	Warrior* warrior2 = new Warrior(Vector2(400, 200));
	warrior2->get_animator()->get_animation("Idle")->set_interval(700);
	Warrior* warrior3 = new Warrior(Vector2(600, 200));
	warrior3->get_animator()->get_animation("Idle")->set_interval(1000);
	Warrior* warrior4 = new Warrior(Vector2(800, 200));
	warrior4->get_animator()->get_animation("Idle")->set_interval(1500);
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

		this->clock->restart();
	}
}
void Game::update_graphics()
{
	this->window->clear();
	GameDrawableContainer::update(*Game::window);	
	this->camera->update(double(this->clock->getElapsedTime().asSeconds()));
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

	float left = Math::percent_of(0.03f, this->window->getSize().x);
	float right = Math::percent_of(0.97f, this->window->getSize().x);
	float up = Math::percent_of(0.03f, this->window->getSize().y);
	float down = Math::percent_of(0.97f, this->window->getSize().y);
	if (sf::Mouse::getPosition().x <= left)
	{
		Vector2 position = this->camera->get_position() + Vector2::right;
		this->camera->move_to(position);
	}
	if (sf::Mouse::getPosition().x >= right)
	{
		Vector2 position = this->camera->get_position() + Vector2::left;
		this->camera->move_to(position);
	}
	if (sf::Mouse::getPosition().y <= down)
	{
		Vector2 position = this->camera->get_position() + Vector2::up;
		this->camera->move_to(position);
	}
	if (sf::Mouse::getPosition().y >= up)
	{
		Vector2 position = this->camera->get_position() + Vector2::down;
		this->camera->move_to(position);
	}
}

const sf::Clock* Game::get_clock()
{
	return clock;
}
