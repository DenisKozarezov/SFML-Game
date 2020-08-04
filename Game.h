#pragma once
#include "SFML/Graphics.hpp"
#include "DrawableContainer.h"
#include "Warrior.h"
#include "Player.h"
#include "PlayerInput.h"
#include "Vector2.h"
#include "GUI.h"
#include "Camera.h"

class Game
{
private:
	sf::RenderWindow* window;
	sf::Clock* clock = new sf::Clock;
	sf::Time* time = new sf::Time;

	Camera* camera = new Camera;
	GUI* gui;

	Player* player = new Player;

	void initialize();
	void graphics_update();
	void input_update();
	void events_update();
public:
	bool* isActive = new bool(false);

	Game();	
	void run();
	void shutdown();

	~Game();
};

