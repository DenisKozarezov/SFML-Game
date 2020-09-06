#pragma once
#include "SFML/Graphics.hpp"
#include "drawable/DrawableContainer.h"
#include "components/unit/Warrior.h"
#include "components/Player/Player.h"
#include "input/PlayerInput.h"
#include "math/Vector2.h"
#include "gui/GUI.h"
#include "components/camera/Camera.h"

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

