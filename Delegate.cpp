#include "Delegate.h"

template<typename T>
Delegate::Delegate(T* type, void(T::*function)())
{
	this->functions.push_back(Member<T>(type, function));
}

void Delegate::invoke()
{
	if (this->functions.size() > 0)
	{
		for (auto it = this->functions.begin(); it != this->functions.end(); it++) it->invoke();
	}
}
void Delegate::clear()
{
	this->functions.clear();
}

Delegate& Delegate::operator+=(Function::Lyambda lyambda)
{
	this->functions.push_back(Function(lyambda));
	return *this;
}
Delegate& Delegate::operator+=(void(*function)())
{
	this->functions.push_back(Function(function));
	return *this;
}
Delegate& Delegate::operator+=(const Delegate& delegate)
{
	for (auto function : delegate.functions) this->functions.push_back(function);
	return *this;
}

Delegate& Delegate::operator-=(void(*function)())
{
	for (auto it = this->functions.begin(); it != this->functions.end(); it++)
	{
		if (it->function == function)
		{
			this->functions.erase(it);
			break;
		}
	}
	return *this;
}
template<typename T>
Delegate& Delegate::operator-=(void(T::*function)())
{
	for (auto it = this->functions.begin(); it != this->functions.end(); it++)
	{
		Member<T> member = dynamic_cast<Delegate::Member<T>*>(*it);
		if (member.member == function) this->functions.erase(it);
	}
	return *this;
}

void Delegate::Function::invoke()
{
	if (this->function) this->function();
	if (this->lyambda) this->lyambda();
}
template<typename T>
void Delegate::Member<T>::invoke()
{
	if (this->member) (this->type->*member)();
}
