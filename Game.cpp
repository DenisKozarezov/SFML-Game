#include "Game.h"
#include <iostream>

sf::Clock *Game::clock = new sf::Clock;
Game::Game()
{
	this->initialize();
	GameDrawableContainer::initialize();

	Warrior* warrior = new Warrior(500, 100);
	this->player = new Player(warrior);	

	sf::Texture* texture1 = new sf::Texture;
	texture1->loadFromFile(ProjectResourcesPath::Sprites + "1.jpg");
	sf::Texture* texture2 = new sf::Texture;
	texture2->loadFromFile(ProjectResourcesPath::Sprites + "2.jpg");
	sf::Texture mas[] = {*texture1, *texture2};
	Animation* animation = new Animation(mas, 2, this->player->getMainCharacter());
	this->player->getMainCharacter()->get_animator()->add("Idle", animation);
	this->player->getMainCharacter()->get_animator()->play("Idle");
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

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
		{
			player->getMainCharacter()->move(1, 0);
		}
	}
}

const sf::Clock* Game::get_clock()
{
	return clock;
}
