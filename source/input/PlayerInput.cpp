#include "PlayerInput.h"

std::map<const std::string, sf::Keyboard::Key>* PlayerInput::_default_input = new std::map<const std::string, sf::Keyboard::Key>;
std::map<const std::string, sf::Keyboard::Key>* PlayerInput::_current_input = new std::map<const std::string, sf::Keyboard::Key>;
PlayerInput* PlayerInput::instance = 0;

PlayerInput::PlayerInput()
{
	_default_input->insert(std::make_pair<const std::string, sf::Keyboard::Key>("Left", sf::Keyboard::Key::A));
	_default_input->insert(std::make_pair<const std::string, sf::Keyboard::Key>("Right", sf::Keyboard::Key::D));
	_default_input->insert(std::make_pair<const std::string, sf::Keyboard::Key>("Jump", sf::Keyboard::Key::Space));

	std::map< const std::string, sf::Keyboard::Key>::iterator it;
	for (it = _default_input->begin(); it != _default_input->end(); it++)
	{
		_current_input->insert(*it);
	}
}
PlayerInput::~PlayerInput()
{
	_default_input->clear();
	_current_input->clear();
	delete _default_input;
	delete _current_input;
}

PlayerInput* PlayerInput::get_instance()
{
	if (!instance) instance = new PlayerInput;
	return instance;
}

const sf::Keyboard::Key& PlayerInput::Left()
{
	return _current_input->find("Left")->second;
}
const sf::Keyboard::Key& PlayerInput::Right()
{
	return _current_input->find("Right")->second;
}
const sf::Keyboard::Key& PlayerInput::Jump()
{
	return _current_input->find("Jump")->second;
}

void PlayerInput::change_key(const std::string& key, const sf::Keyboard::Key& value)
{
	std::map<const std::string, sf::Keyboard::Key>::iterator it = _current_input->find(key);
	if (it != _current_input->end()) _current_input->find(key)->second = value;
}
void PlayerInput::reset()
{
	std::map<const std::string, sf::Keyboard::Key>::iterator it;
	for (it = _default_input->begin(); it != _default_input->end(); it++)
	{
		_current_input->find(it->first)->second = it->second;
	}
}