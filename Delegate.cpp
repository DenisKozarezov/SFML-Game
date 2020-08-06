#include "Delegate.h"

Delegate::Delegate(Function<> function)
{
	this->func = function;
}
template<typename T, typename ...Args>
Delegate::Delegate(void(T::*function)(const Args&... args))
{
	this->func = function;
}

template<typename... Args>
void Delegate::invoke(const Args&... args)
{
	if (this->func) this->func(args...);
}

Delegate& Delegate::operator+=(Function<> function)
{
	this->func = func;
	return *this;
}
template<typename T, typename... Args>
Delegate& Delegate::operator+=(void(T::* function)(const Args&...))
{
	this->func = function;
	return *this;
}
