#include "GUI.h"
#include "GUIText.h"
#include "GUIImage.h"
#include "GUIButton.h"
#include "GUITextField.h"

GUI* GUI::instance = 0;
GUI::GUI()
{
	this->focused = new bool(0);
	this->hidden = new bool(0);
	this->elements = new std::list<GUIElement*>;
	this->colliders = new std::list<Collision*>;
}

void GUI::add(GUIElement* element)
{
	GUI::get_instance()->elements->push_back(element);
}
void GUI::add(Collision* collider)
{
	GUI::get_instance()->colliders->push_back(collider);
}

void GUI::show(const bool& status)
{
	
}
void GUI::focus(const bool& status)
{
	*GUI::get_instance()->focused = status;
}

void GUI::initialize()
{
	GUIText* hp = new GUIText(Vector2(200, 100), "Health: 0");
	hp->set_color(sf::Color::Red);
	hp->set_font_size(20);

	sf::Texture heart_texture;
	heart_texture.loadFromFile(ProjectResourcesPath::Sprites + "heart.png");
	GUIImage* heart = new GUIImage(Rect(200, 50, 50, 50), heart_texture);

	GUIText* mp = new GUIText(Vector2(500, 100), "Mana: 0");
	mp->set_color(sf::Color::Blue);
	mp->set_font_size(20);

	sf::Texture mp_texture;
	mp_texture.loadFromFile(ProjectResourcesPath::Sprites + "mana.png");
	GUIImage* mana = new GUIImage(Rect(500, 50, 50, 50), mp_texture);

	GUIText* dmg = new GUIText(Vector2(700, 100), "Damage: 0");
	dmg->set_color(sf::Color::Yellow);
	dmg->set_font_size(20);

	sf::Texture damage_texture;
	damage_texture.loadFromFile(ProjectResourcesPath::Sprites + "owl.jpg");
	GUIImage* damage = new GUIImage(Rect(700, 50, 50, 50), damage_texture);

	GUIButton* button1 = new GUIButton(Rect(200, 1000, 200, 50), "BUTTON");
	*button1->OnClick += [button1]() { button1->set_text("CLICKED!"); };
	*button1->OnPointerEnter += [button1]() { button1->set_text("ENTER!"); };
	*button1->OnPointerEnter += [button1]() { std::abs(1); };
	*button1->OnPointerExit += [button1]() { button1->set_text("EXIT!"); };
	*button1->OnActive += [button1]() { button1->set_text("ACTIVE!"); };

	GUITextField* field = new GUITextField(Rect(1500, 1000, 400, 30), "TEXT FIELD");
}

GUI* GUI::get_instance()
{
	if (!instance) instance = new GUI;
	return instance;
}

const bool& GUI::IsHidden() 
{
	return *GUI::get_instance()->hidden;
}
const bool& GUI::IsFocused()
{
	return *GUI::get_instance()->focused;
}

void GUI::update(sf::RenderWindow& window, sf::Event& event)
{
	if (this->elements->size() > 0)
	{
		for (auto object : *elements)
		{
			object->input_update(event);
			if (object->drawable_object && !object->IsHidden()) window.draw(*object->drawable_object);
		}
	}

	if (this->colliders->size() > 0)
	{
		for (auto object : *colliders)
		{
			if (object->outline && *object->showOutline) window.draw(*object->outline);
		}
	}
}