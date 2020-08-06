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
	sf::Event* event;
	sf::Clock* clock;
	sf::Time* time;

	Camera* camera;
	GUI* gui;

	Player* player;

	void initialize();
	void graphics_update();
	void input_update();
	void events_update();
public:
	static sf::RenderWindow* window;

	bool* isActive;

	Game();	
	void run();
	void shutdown();

	~Game();
};

