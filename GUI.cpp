#include "GUI.h"
#include "DrawableContainer.h"
#include "Player.h"
#include <iostream>

GUI* GUI::instance = 0;

void GUI::add(GUIElement* element)
{
	GUI::get_instance()->text->push_back(element);
}
void GUI::initialize()
{
	this->hp = new GUIText(Vector2(200, 100), "");
	this->hp->set_color(sf::Color::Red);
	this->hp->set_size(20);

	sf::Texture heart_texture;
	heart_texture.loadFromFile(ProjectResourcesPath::Sprites + "heart.png");
	GUIImage* heart = new GUIImage(Rect(200, 50, 50, 50), heart_texture);

	this->mp = new GUIText(Vector2(500, 100), "");
	this->mp->set_color(sf::Color::Blue);
	this->mp->set_size(20);

	sf::Texture mp_texture;
	mp_texture.loadFromFile(ProjectResourcesPath::Sprites + "mana.png");
	GUIImage* mp = new GUIImage(Rect(500, 50, 50, 50), mp_texture);

	this->damage = new GUIText(Vector2(700, 100), "");
	this->damage->set_color(sf::Color::Yellow);
	this->damage->set_size(20);

	sf::Texture damage_texture;
	damage_texture.loadFromFile(ProjectResourcesPath::Sprites + "owl.jpg");
	GUIImage* damage = new GUIImage(Rect(700, 50, 50, 50), damage_texture);
}

GUI::GUI()
{
	this->hidden = new bool(0);
	this->text = new std::vector<GUIElement*>;
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

void GUI::update(sf::RenderWindow& window, sf::Event& event)
{
	if (this->text->size() > 0)
	{
		for (auto object : *text)
		{
			object->input_update(event);
			if (object->drawable_object) window.draw(*object->drawable_object);
		}
	}
	this->hp->set_text("Health: " + std::to_string(Player::get_main_player()->get_main_character()->get_health()));
	this->mp->set_text("Mana: -");
	this->damage->set_text("Damage: " + std::to_string(Player::get_main_player()->get_main_character()->get_damage()));
}