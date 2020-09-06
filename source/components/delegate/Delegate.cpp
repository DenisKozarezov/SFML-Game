#include "Delegate.h"

//template<typename T, typename Type>
//Delegate<T>::Delegate(Type* type, void(Type::*function)())
//{
//	this->functions.push_back(Member<T>(type, function));
//}
//template<typename... Args>
//Delegate<Args...>& Delegate<Args...>::operator+=(Func function)
//{
//	this->functions.push_back(Function(function));
//	return *this;
//}
//template<typename... Args>
//Delegate<Args...>& Delegate<Args...>::operator+=(Lyambda lyambda)
//{
//	this->functions.push_back(Function(lyambda));
//	return *this;
//}
//template<typename... Args>
//Delegate<Args...>& Delegate<Args...>::operator+=(const Delegate<Args...>& delegate)
//{
//	for (auto function : delegate.functions) this->functions.push_back(function);
//	return *this;
//}

//Delegate& Delegate::operator-=(void(*function)())
//{
//	for (auto it = this->functions.begin(); it != this->functions.end(); it++)
//	{
//		if (it->function == function)
//		{
//			this->functions.erase(it);
//			break;
//		}
//	}
//	return *this;
//}
//
//template<typename T>
//Delegate& Delegate::operator-=(void(T::*function)())
//{
//	for (auto it = this->functions.begin(); it != this->functions.end(); it++)
//	{
//		Member<T> member = dynamic_cast<Delegate::Member<T>*>(*it);
//		if (member.member == function) this->functions.erase(it);
//	}
//	return *this;
//}
