#include "GUI.h"
#include "DrawableContainer.h"
#include "Player.h"

GUI* GUI::instance = 0;

void GUI::add(sf::Drawable* object)
{
	GUI::get_instance()->text->push_back(object);
}
void GUI::initialize()
{
	this->hp = new GUIText(Vector2(200, 100), "");
	this->hp->set_color(sf::Color::Red);
	this->hp->set_size(20);

	this->mp = new GUIText(Vector2(500, 100), "");
	this->mp->set_color(sf::Color::Blue);
	this->mp->set_size(20);

	this->damage = new GUIText(Vector2(700, 100), "");
	this->damage->set_color(sf::Color::Yellow);
	this->damage->set_size(20);

	sf::Texture texture;
	texture.loadFromFile("C:/Users/Acer/source/repos/Game/x64/resources/sprites/owl.jpg");
	GUIImage* image = new GUIImage(Rect(200, 200, 100, 100), texture);
	image->set_size(50, 50);
}

GUI::GUI()
{
	this->hidden = new bool(0);
	this->text = new std::vector<sf::Drawable*>;
}
GUI* GUI::get_instance()
{
	if (!instance) instance = new GUI;
	return instance;
}

const bool& GUI::IsHidden() const
{
	return *this->hidden;
}

void GUI::show(const bool& status)
{
	
}

void GUI::update(sf::RenderWindow& window)
{
	if (this->text->size() > 0)
	{
		for (auto object : *text)
		{
			window.draw(*object);
		}
	}

	this->hp->set_text("Health: " + std::to_string(Player::get_main_player()->get_main_character()->get_health()));
	this->mp->set_text("Mana: -");
	this->damage->set_text("Damage: " + std::to_string(Player::get_main_player()->get_main_character()->get_damage()));
}
