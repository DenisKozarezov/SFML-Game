#pragma once
#include "SFML/Graphics.hpp"
#include "Drawable.h"
#include "Warrior.h"
#include "Player.h"
#include "Camera.h"
#include "Vector2.h"

class Game
{
private:
	sf::RenderWindow* window;
	static sf::Clock* clock;
	static sf::Time* time;

	static Camera* camera;

	Player* player;

	void initialize();
	void update_graphics();
	void update_input();
	void update_events();
public:
	bool* isActive = new bool(false);

	Game();	
	void run();
	void shutdown();

	const static sf::Clock* get_clock();
	~Game();
};

