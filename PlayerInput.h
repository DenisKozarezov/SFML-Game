#pragma once
#include "SFML/Graphics.hpp"
#include <map>

class PlayerInput final
{
private:
	static std::map<const std::string, sf::Keyboard::Key>* _default_input;
	static std::map<const std::string, sf::Keyboard::Key>* _current_input;

	static PlayerInput* instance;

	PlayerInput();

	PlayerInput& operator=(const PlayerInput&) = delete;
public:
	static PlayerInput* get_instance();

	const static sf::Keyboard::Key& Left();
	const static sf::Keyboard::Key& Right();
	const static sf::Keyboard::Key& Jump();

	static void change_key(const std::string& key, const sf::Keyboard::Key& value);
	static void reset();

	~PlayerInput();
};

