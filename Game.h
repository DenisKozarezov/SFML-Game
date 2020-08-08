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

	static Game* instance;

	bool* focused;

	void initialize();
	void graphics_update();
	void input_update();
	void events_update();
public:
	static sf::RenderWindow* window;
	static Game* get_instance();

	Game();	

	static void run();
	static void focus(const bool& status);
	static void quit();

	static const bool* IsFocused();

	~Game();
};

