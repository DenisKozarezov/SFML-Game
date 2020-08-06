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

void Delegate::invoke()
{
	if (this->func) this->func();
}

const bool& Delegate::IsNull() const
{
	return this->func;
}

Delegate& Delegate::operator+=(Function<> function)
{
	this->func = func;
	return *this;
}
Delegate& Delegate::operator=(const Delegate& delegate)
{
	this->func = delegate.func;
	return *this;
}
bool Delegate::operator==(const Delegate& delegate)
{
	return this->func == delegate.func;
}
bool Delegate::operator!=(const Delegate& delegate)
{
	return !(this->func == delegate.func);
}
template<typename T, typename... Args>
Delegate& Delegate::operator+=(void(T::* function)(const Args&...))
{
	this->func = function;
	return *this;
}