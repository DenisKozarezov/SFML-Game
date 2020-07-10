#include "Warrior.h"

Warrior::Warrior(const float&x, const float&y)
{
	set_health(100);
	set_speed(25);
}

Warrior::~Warrior()
{

}

void Warrior::update()
{
	
}

const Warrior& Warrior::operator=(const Warrior& unit)
{
	return *this;
}
const bool operator==(const Warrior& unit1, const Warrior& unit2)
{
	return unit1 == unit2;
}
const bool operator!=(const Warrior& unit1, const Warrior& unit2)
{
	return !(unit1 == unit2);
}