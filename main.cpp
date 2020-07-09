#include <SFML/Graphics.hpp>
#include "Warrior.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "My Game");
	GameDrawableContainer::initialize();

	sf::Thread thread([]() {
		Warrior* warrior1 = new Warrior(580, 400);
		});
	thread.launch();

	sf::RenderWindow* MainWindow;
	MainWindow = &window;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		window.clear();
		GameDrawableContainer::render(window);		
		window.display();
	}
	return 0;
}