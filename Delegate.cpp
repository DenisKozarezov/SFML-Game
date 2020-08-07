#include "Delegate.h"

void Delegate::invoke()
{
	std::vector<Function>::iterator it;
	for (it = this->functions.begin(); it != this->functions.end(); it++) it->invoke();
}

const bool& Delegate::IsNull() const
{
	return this->functions.size() == 0;
}

Delegate& Delegate::operator+=(Function::Lyambda lyambda)
{
	this->functions.push_back(Function(lyambda));
	return *this;
}
template<typename T, typename ...Args>
Delegate& Delegate::operator+=(void(T::* function)(const Args...))
{
	this->functions.push_back(Function(function));
	return *this;
}
Delegate& Delegate::operator+=(const Delegate& delegate)
{
	for (auto function : delegate.functions) this->functions.push_back(function);
	return *this;
}

template<typename T, typename ...Args>
Delegate& Delegate::operator-=(void(T::* function)(const Args...))
{
	std::vector<Function>::iterator first = this->functions.begin();
	std::vector<Function>::iterator last = this->functions.end();
	std::vector<Function>::iterator find = std::find(first, last, function);
	if (find != last) this->functions.erase(find);
	return *this;
}

Delegate& Delegate::operator=(const Delegate& delegate)
{
	this->functions = delegate.functions;
	return *this;
}

void Delegate::Function::invoke()
{
	if (this->_function) _function();
	if (this->_lyambda) this->_lyambda();
}
