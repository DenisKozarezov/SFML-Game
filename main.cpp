#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Vector2.h"

int main()
{
	Game* game = Game::get_instance();
	game->run();	
	return 0;
}