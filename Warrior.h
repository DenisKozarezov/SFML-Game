#pragma once
#include "Unit.h"

class Warrior : public Unit
{
private:
	const std::string sprite_name = "warrior.jpg";

	void update() override;
public:	
	Warrior(const float& x, const float& y);

	const Warrior& operator=(const Warrior& unit);	

	~Warrior();
};
const bool operator==(const Warrior& unit1, const Warrior& unit2);
const bool operator!=(const Warrior& unit1, const Warrior& unit2);