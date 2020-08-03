#include "UnitEventHandler.h"

void UnitEventHandler::operator+(const Action& action)
{
	this->event = action;
	this->event();
}
