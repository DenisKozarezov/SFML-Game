#pragma once
#include <list>
#include <functional>

template<typename... Args>
class Delegate
{
private:
	using Function = std::function<void(Args...)>;
	std::list<Function> functions;
public:
	Delegate<Args...>() = default;
	template<typename Type>
	Delegate<Args...>(Type* type, void(Type::*function)());

	/// <summary>
	/// Invokation of all functions that were added in this delegate.
	/// </summary>
	void invoke(Args... args)
	{
		if (this->functions.size() > 0)
		{
			for (Function function : this->functions) function(args...);
		}
	}

	/// <summary>
	/// Clear the list of delegate functions.
	/// </summary>
	void clear()
	{
		this->functions.clear();
	}

	/// <summary>
	/// Adding a function in the delegate, including lambda-expressions.
	/// </summary>
	Delegate<Args...>& operator+=(Function function)
	{
		this->functions.push_back(function);
		return *this;
	}

	/// <summary>
	/// Copying all functions of the delegate-operand.
	/// </summary>
	Delegate<Args...>& operator+=(const Delegate<Args...>& delegate)
	{
		for (auto function : delegate.functions) this->functions.push_back(function);
		return *this;
	}

	Delegate<Args...>& operator-=(void(*function)());
	template<typename Type>
	Delegate<Args...>& operator-=(void(Type::*function)());

	Delegate<Args...>& operator=(const Delegate<Args...>&) = default;
};

template<>
class Delegate<void>
{
private:
	using Function = std::function<void()>;
	std::list<Function> functions;
public:
	Delegate() = default;
	template<typename T>
	Delegate(T* type, void(*function)());

	/// <summary>
	/// Invokation of all functions that were added in this delegate.
	/// </summary>
	void invoke()
	{
		if (this->functions.size() > 0)
		{
			for (Function function : this->functions) function();
		}
	}

	/// <summary>
	/// Clear the list of delegate functions.
	/// </summary>
	void clear()
	{
		this->functions.clear();
	}

	/// <summary>
	/// Adding a function in the delegate, including lambda-expressions.
	/// </summary>
	Delegate<void>& operator+=(Function function)
	{
		this->functions.push_back(Function(function));
		return *this;
	}

	/// <summary>
	/// Copying all functions of the delegate-operand.
	/// </summary>
	Delegate<void>& operator+=(const Delegate<void>& delegate)
	{
		for (auto function : delegate.functions) this->functions.push_back(function);
		return *this;
	}

	Delegate<void>& operator-=(void(*function)());
	template<typename T>
	Delegate<void>& operator-=(void(T::* function)());

	Delegate<void>& operator=(const Delegate<void>&) = default;
};