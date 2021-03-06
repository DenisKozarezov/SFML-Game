#pragma once
#include "Unit.h"

class Warrior : public Unit
{
private:
	void update() override;
public:	
	Warrior(const Vector2& position);

	const Warrior& operator=(const Warrior& unit);	

	~Warrior();
};
const bool operator==(const Warrior& unit1, const Warrior& unit2);
const bool operator!=(const Warrior& unit1, const Warrior& unit2);